#include "passerelle.h"

passerelle::passerelle() {
    serveur = new QTcpServer;
    tailleMessage = 0;



    QLabel* label = new QLabel;

    if(serveur->listen(QHostAddress::Any,PASSERELLE_PORT)) {
        connect(serveur, SIGNAL(newConnection()), this, SLOT(nouvelleConnexion()));
        label->setText("Serveur d�marr� sur le port "+QString::number(PASSERELLE_PORT)+".");
    }
    else {
        label->setText("Le serveur de la passerelle n'a pas pu d�marrer !");
    }

    label->setWindowTitle("Passerelle");
    label->show();

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
    m_toSend.enqueue(m);

    tailleMessage = 0;
}

void passerelle::deconnexionClient()
{
    // On d�termine quel client se d�connecte
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // Si par hasard on n'a pas trouv� le client � l'origine du signal, on arr�te la m�thode
        return;

    clients.removeOne(socket);

    socket->deleteLater();
}

void passerelle::envoyer(const QString &message, int dest) {
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    out << (quint32) 0; // On �crit 0 au d�but du paquet pour r�server la place pour �crire la taille
    out << message; // On ajoute le message � la suite
    out.device()->seek(0); // On se replace au d�but du paquet
    out << (quint32) (paquet.size() - sizeof(quint32)); // On �crase le 0 qu'on avait r�serv� par la longueur du message

    if(clients.size() > dest) {
        clients[dest]->write(paquet);
    }
}

void passerelle::actQueue() {
    if(m_toSend.size() != 0) {
        Message mess = m_toSend.dequeue();
        if(mess.index != -1) {
            if(mess.index != -2)
                envoyer(mess.message,mess.index);
        }
        else if(mess.demande == false) {
            askByFile(mess.pseudo);
            mess.demande = true;
            m_toSend.enqueue(mess);
        }
        else {
            m_toSend.enqueue(mess);
            actInFile();
        }
    }
}

void passerelle::askByFile(QString pseudo) {
    QFile file("./ask");
    if(file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
            out << pseudo << endl;
    }
}

void passerelle::actInFile() {
    QFile file("./answer");
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
        for(int i2 = 0;i2 < m_toSend.size();i2++) {
            if(m_toSend[i2].pseudo == pseudo) {
                if(curIndex == -1)
                    m_toSend[i2].index = -2;
                else
                    m_toSend[i2].index = curIndex;
            }
        }

    }

    file.remove();
    file.close();
}
