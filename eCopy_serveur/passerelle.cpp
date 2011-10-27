#include "passerelle.h"

passerelle::passerelle() {
    serveur = new QTcpServer;
    tailleMessage = 0;

    QWidget* dial = new QWidget;
    dial->setWindowTitle("Passerelle de connexion");

    QVBoxLayout *layout = new QVBoxLayout;

    QLabel* label = new QLabel;

    if(serveur->listen(QHostAddress::Any,PASSERELLE_PORT)) {
        connect(serveur, SIGNAL(newConnection()), this, SLOT(nouvelleConnexion()));
        label->setText("Serveur démarré sur le port "+QString::number(PASSERELLE_PORT)+".");
    }
    else {
        label->setText("Le serveur de la passerelle n'a pas pu démarrer !");
    }

    layout->addWidget(label);

    etat = new QTextBrowser;

    layout->addWidget(etat,5);

    dial->setLayout(layout);
    dial->show();

    m_watchQueue = new QTimer;
    connect(m_watchQueue,SIGNAL(timeout()),this,SLOT(actQueue()));
    m_watchQueue->start(100);
}

passerelle::~passerelle() {
    delete m_watchQueue;
}

void passerelle::nouvelleConnexion()
{
    QTcpSocket *nouveauClient = serveur->nextPendingConnection();
    clients << nouveauClient;

    connect(nouveauClient, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(nouveauClient, SIGNAL(disconnected()), this, SLOT(deconnexionClient()));

}

void passerelle::donneesRecues()
{
   QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0)
        return;

    QDataStream in(socket);

    if (tailleMessage == 0)
    {
        if (socket->bytesAvailable() < (int)sizeof(quint32))
             return;

        in >> tailleMessage;
    }

    if (socket->bytesAvailable() < tailleMessage)
        return;

    QString message;
    in >> message;


    QStringList decomp = message.split(" ");
    QString pseudo = "";
    int taille = decomp[0].toInt();
    decomp.removeFirst();
    for(int i=0;i<taille;i++) {
        pseudo += decomp[0];
        decomp.removeFirst();
        if(i!=taille-1)
            pseudo += " ";
    }



    Message m;
    m.demande = false;
    m.index = -1;
    m.pseudo = pseudo;
    m.message = decomp.join(" ");

    m_toSend.append(m);

    //m_toSend.enqueue(m);

    tailleMessage = 0;
}

void passerelle::deconnexionClient()
{
    // On détermine quel client se déconnecte
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // Si par hasard on n'a pas trouvé le client à l'origine du signal, on arrête la méthode
        return;

    clients.removeOne(socket);

    socket->deleteLater();
}

void passerelle::envoyer(const QString &message, int dest) {
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    out << (quint32) 0; // On écrit 0 au début du paquet pour réserver la place pour écrire la taille
    out << message; // On ajoute le message à la suite
    out.device()->seek(0); // On se replace au début du paquet
    out << (quint32) (paquet.size() - sizeof(quint32)); // On écrase le 0 qu'on avait réservé par la longueur du message

    if(clients.size() > dest) {
        clients[dest]->write(paquet);
    }
}

void passerelle::actQueue() {
    //for(int i=0;i<m_toSend.size();i++) {
       // QMessageBox::information(NULL,"Test",m_toSend.at(i).message + " de " + m_toSend.at(i).pseudo + " sur index " + QString::number(m_toSend.at(i).index) + " demande " + m_toSend.at(i).demande) ;
    //}

    if(m_toSend.size() != 0) {
        Message mess = m_toSend[0];
      //  Message mess = m_toSend.dequeue();
        if(mess.index != -1) {
            if(mess.index != -2) {
                clients[mess.index]->waitForBytesWritten();
                envoyer(mess.message,mess.index);
                etat->append(mess.message + " envoié à " + mess.pseudo);
            }
            m_toSend.remove(0);
        }
        else if(mess.demande == false) {
            askByFile(mess.pseudo);



          //  mess.demande = true;
            m_toSend[0].demande = true;
      //      m_toSend.enqueue(mess);
        }
        else {
       //     m_toSend.enqueue(mess);
            actInFile();
        }
    }
}

void passerelle::askByFile(QString pseudo) {
#ifdef _WIN32
    QFile file(".\\ask");
#else
    QFile file("./ask");
#endif

    if(file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
            out << pseudo << endl;
    }
}

void passerelle::actInFile() {
#ifdef _WIN32
    QFile file(".\\answer");
#else
    QFile file("./answer");
#endif
    QStringList lines;


    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString in = file.readAll();
        lines = in.split("\n");
    }
    else
        return;


    for(int i=0;i<lines.size();i++) {
        QStringList curLine = lines[i].split(" ");
        int curIndex = curLine[0].toInt();
        curLine.removeFirst();
        QString pseudo = curLine.join(" ");
       /* for(int i2 = 0;i2 < m_toSend.size();i2++) {
            if(m_toSend[i2].pseudo == pseudo) {
                if(curIndex == -1)
                    m_toSend[i2].index = -2;
                else
                    m_toSend[i2].index = curIndex;
            }
        }*/
        if(m_toSend[0].pseudo == pseudo) {
            if(curIndex == -1)
                m_toSend[0].index = -2;
            else
                m_toSend[0].index = curIndex;
        }

    }

    file.remove();
    file.close();
}
