#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    setWindowTitle(tr("eCopy - Serveur"));

#ifndef WITH_MYSQL
    m_pseudos << "lucas" << "test";
    m_pass << "40bd001563085fc35165329ea1ff5c5ecbdbbeef" << "40bd001563085fc35165329ea1ff5c5ecbdbbeef";
    m_co << "Déconnecté" << "Déconnecté";
    m_indexSock << -1 << -1;

    majListe();
#endif

    // Gestion du serveur
    serveur = new QTcpServer(this);
    if (!serveur->listen(QHostAddress::Any, 2011)) // Démarrage du serveur sur toutes les IP disponibles et sur le port 50585
    {
        // Si le serveur n'a pas été démarré correctement
        etat->setText(tr("Le serveur n'a pas pu être démarré. Raison :<br />") + serveur->errorString());
    }
    else
    {
        // Si le serveur a été démarré correctement
        etat->setText(tr("Le serveur a été démarré sur le port <strong>") + QString::number(serveur->serverPort()) + tr("</strong>.<br />Des clients peuvent maintenant se connecter."));
        connect(serveur, SIGNAL(newConnection()), this, SLOT(nouvelleConnexion()));
    }

    tailleMessage = 0;

    getUsers();

    actUser = new QTimer;
    connect(actUser,SIGNAL(timeout()),this,SLOT(act()));
    actUser->start(15000);

    actInputFile = new QTimer;
    connect(actInputFile,SIGNAL(timeout()),this,SLOT(readInputFile()));
    actInputFile->start(100);


    QStringList args;
    args << "gtw";
    QProcess::startDetached(qApp->argv()[0],args);

}

MainWindow::~MainWindow()
{
    delete actUser;
}

void MainWindow::nouvelleConnexion()
{
    QTcpSocket *nouveauClient = serveur->nextPendingConnection();
    clients << nouveauClient;

    connect(nouveauClient, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(nouveauClient, SIGNAL(disconnected()), this, SLOT(deconnexionClient()));
}

void MainWindow::donneesRecues()
{
   QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0)
        return;

    QDataStream in(socket);

    if (tailleMessage == 0)
    {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
             return;

        in >> tailleMessage;
    }

    if (socket->bytesAvailable() < tailleMessage)
        return;

    QString message;
    in >> message;



    exec(message,clients.indexOf(socket));

    tailleMessage = 0;
}

void MainWindow::exec(QString cmd,int from) {
    QStringList decomp = cmd.split(" ");
    if(decomp[0].toUpper()=="LOGON") {
        QString pass = decomp[1];
        decomp.removeFirst();
        decomp.removeFirst();

        QString pseudo = decomp.join(" ");

        int index = m_pseudos.indexOf(pseudo);
        if(index != -1) {
            if(m_pass[index]==pass) {
                m_co[index] = "Connecté";
                m_indexSock[index] = from;
                majListe();
                envoyer("LOGGED",from);
            }
            else {
                envoyer("BAD PASSWORD",from);
            }
        }
        else {
            envoyer("BAD ID",from);
        }
    }
    else if(decomp[0].toUpper()=="SEARCH"){
        decomp.removeFirst();
        int index = m_pseudos.indexOf(decomp.join(" "));
        if(index!=-1) {
            QString message = "FOUND ";
            if(m_indexSock[index] != -1){
                message += clients[m_indexSock[index]]->peerAddress().toString() + " ";
            } else {
                message += "0.0.0.0 ";
            }
            message += decomp.join(" ");
            envoyer(message,from);
        }
        else {
            envoyer("NOT_FOUND",from);
        }
    }
    else if(decomp[0].toUpper()=="CHAT") {
        int taillePseudo = decomp[1].toInt();
        decomp.removeFirst();
        decomp.removeFirst();
        QString pseudo("");
        for(int i=0;i<taillePseudo;i++) {
            pseudo += decomp[0];
            decomp.removeFirst();
            if(i != taillePseudo - 1)
                pseudo += " ";
        }

    }
    else  {
        envoyer("UNKNOWN",from);
    }


}

void MainWindow::majListe(){

    QStringListModel *modeleCo = new QStringListModel(m_co);
    listeCo->setModel(modeleCo);

    QStringListModel *modeleId = new QStringListModel(m_pseudos);
    listePseudo->setModel(modeleId);

    QStringListModel *modelePass = new QStringListModel(m_pass);
    listePass->setModel(modelePass);

    QStringList liste_sock;
    for(int i=0;i<m_indexSock.size();i++) {
        liste_sock << QString::number(m_indexSock[i]);
    }

    QStringListModel *modeleSock = new QStringListModel(liste_sock);
    listeSocket->setModel(modeleSock);
}

void MainWindow::deconnexionClient()
{
    // On détermine quel client se déconnecte
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // Si par hasard on n'a pas trouvé le client à l'origine du signal, on arrête la méthode
        return;

    int index = clients.indexOf(socket);
    clients.removeOne(socket);

    if(m_indexSock.indexOf(index) != -1) {
        m_co[m_indexSock.indexOf(index)] = "Déconnecté";
        m_indexSock.replace(index,-1);
    }


    for(int i=0;i<m_indexSock.size();i++){
        if((m_indexSock[i] != -1)&&(m_indexSock[i] >= index )) {
            m_indexSock[i]--;
        }
    }

    majListe();

    socket->deleteLater();
}

void MainWindow::envoyer(const QString &message, int dest) {
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    out << (quint16) 0; // On écrit 0 au début du paquet pour réserver la place pour écrire la taille
    out << message; // On ajoute le message à la suite
    out.device()->seek(0); // On se replace au début du paquet
    out << (quint16) (paquet.size() - sizeof(quint16)); // On écrase le 0 qu'on avait réservé par la longueur du message


    clients[dest]->write(paquet);
}



void MainWindow::getUsers(){
#ifdef WITH_MYSQL
    MYSQL bdd;

    mysql_init(&bdd);
    mysql_options(&bdd,MYSQL_READ_DEFAULT_GROUP,"option");



    if(mysql_real_connect(&bdd,BDD_HOST,BDD_USER,BDD_PASS,"ecopy",0,NULL,0))
    {

        mysql_query(&bdd, "SELECT * FROM prog_users");

        MYSQL_RES *result = NULL;
        MYSQL_ROW row = NULL;


        result = mysql_use_result(&bdd);


        QStringList anc_pseudos=m_pseudos;
        QStringList anc_co=m_co;
        QList<int> anc_index=m_indexSock;

        m_pseudos.clear();
        m_pass.clear();
        m_co.clear();
        m_indexSock.clear();


        majListe();

        while ((row = mysql_fetch_row(result)))
        {
           m_pseudos << QString(row[1]);
           m_pass << QString(row[2]);

           int index = anc_pseudos.indexOf(row[1]);
           if(index != -1) {
               m_co << anc_co[index];
               m_indexSock << anc_index[index];
           }
           else {
               m_co << "Déconnecté";
               m_indexSock << -1;
           }
        }
        mysql_free_result(result);

        //mysql_close(&bdd);
        majListe();
    }
    else
    {
        etat->append("Erreur lors de la connexion à la base de données.");
    }
#endif
}

int MainWindow::getSocketIdByName(QString pseudo) {
    int index = m_pseudos.indexOf(pseudo);
   // QMessageBox::information(this,"Title","Information: "+m_pseudos.join(" : "));
   // if((m_pseudos[0] == pseudo) && (m_pseudos[1] == pseudo))
      //  QMessageBox::information(this,"Trololol","Trololol");
  //  QMessageBox::information(this,"Title","Information: "+pseudo+" => "+QString::number(index));

    if(index != -1) {
        return m_indexSock[index];
    }
    else {
        return -1;
    }
}

void MainWindow::writeOutput(QString text) {
#ifdef _WIN32
    QFile file(".\\answer");
#else
    QFile file("./answer");
#endif
    if(file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);

            out << text << endl;
    }
}

void MainWindow::readInputFile() {
#ifdef _WIN32
    QFile file(".\\ask");
#else
    QFile file("./ask");
#endif
    if(!file.open(QIODevice::ReadOnly))
        return;

    QString text = file.readAll();
    file.remove();
    file.close();

    QStringList lines = text.split("\n");
    for(int i=0;i<lines.size();i++) {
        writeOutput(QString::number(getSocketIdByName(lines[i]))+" "+lines[i]);
    }
}

