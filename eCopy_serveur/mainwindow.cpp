#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    setWindowTitle(tr("eCopy - Serveur"));

    // Gestion du serveur
    serveur = new QTcpServer(this);
    if (!serveur->listen(QHostAddress::Any, 2011)) // D�marrage du serveur sur toutes les IP disponibles et sur le port 50585
    {
        // Si le serveur n'a pas �t� d�marr� correctement
        etat->setText(tr("Le serveur n'a pas pu �tre d�marr�. Raison :<br />") + serveur->errorString());
    }
    else
    {
        // Si le serveur a �t� d�marr� correctement
        etat->setText(tr("Le serveur a �t� d�marr� sur le port <strong>") + QString::number(serveur->serverPort()) + tr("</strong>.<br />Des clients peuvent maintenant se connecter."));
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
                m_co[index] = "Connect�";
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
}

void MainWindow::deconnexionClient()
{
    // On d�termine quel client se d�connecte
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // Si par hasard on n'a pas trouv� le client � l'origine du signal, on arr�te la m�thode
        return;

    int index = clients.indexOf(socket);
    clients.removeOne(socket);

    if(m_indexSock.indexOf(index) != -1) {
        m_co[m_indexSock.indexOf(index)] = "D�connect�";
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

    out << (quint16) 0; // On �crit 0 au d�but du paquet pour r�server la place pour �crire la taille
    out << message; // On ajoute le message � la suite
    out.device()->seek(0); // On se replace au d�but du paquet
    out << (quint16) (paquet.size() - sizeof(quint16)); // On �crase le 0 qu'on avait r�serv� par la longueur du message


    clients[dest]->write(paquet);
}


/* m_pseudos << query.value(1).toString();
 m_pass << query.value(2).toString();
 m_co << "D�connect�";*/
void MainWindow::getUsers(){
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
               m_co << "D�connect�";
               m_indexSock << -1;
           }
        }
        mysql_free_result(result);

        //mysql_close(&bdd);
        majListe();
    }
    else
    {
        etat->append("Erreur lors de la connexion � la base de donn�es.");
    }
}

int MainWindow::getSocketIdByName(QString pseudo) {
    int index = m_pseudos.indexOf(pseudo);

    if(index != -1) {
        return m_indexSock[index];
    }
    else {
        return -1;
    }
}

void MainWindow::writeOutput(QString text) {
    QFile file("./answer");
    if(file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);

            out << text << endl;
    }
}

void MainWindow::readInputFile() {
    QFile file("./ask");
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

