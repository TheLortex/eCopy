#include "network.h"

Network::Network()
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(messageRecu()));
    connect(socket, SIGNAL(connected()), this, SLOT(connecte()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(deconnecte()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));

    tailleMessage = 0;
}

void Network::connecter() {
    socket->abort();
    socket->connectToHost(SERVER_IP,PORT);
}

void Network::envoyer(QString message) {

    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On prépare le paquet à envoyer

    out << (quint16) 0;
    out << message;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    socket->write(paquet);
}

void Network::connecte() {
    emit event(CONNECTE,"Connexion au serveur réussie");
}

void Network::deconnecte() {
    emit event(DECONNECTE,"Déconnecté du serveur");
}

void Network::erreurSocket(QAbstractSocket::SocketError erreur) {
    QString message;

    switch(erreur) {
    case QAbstractSocket::RemoteHostClosedError:
        message = "Vous avez été déconnecté du serveur, veuillez vous reconnecter.";
        break;
    case QAbstractSocket::ConnectionRefusedError:
        message = "Connexion refusée par le serveur, veuillez réessayer plus tard.";
        break;
    case QAbstractSocket::HostNotFoundError:
        message = "Serveur introuvable, êtes vous connecté à internet ?";
        break;
    default:
        message = "Erreur de connexion, veuillez réessayer plus tard.";
        break;
    }

    emit event(ERREUR,message);
}

void Network::messageRecu() {
    QDataStream in(socket);

    if (tailleMessage == 0)
    {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
             return;

        in >> tailleMessage;
    }

    if (socket->bytesAvailable() < tailleMessage)
        return;


    QString messageRecu;
    in >> messageRecu;


    tailleMessage = 0;
    emit event(MESSAGE,messageRecu);
}

