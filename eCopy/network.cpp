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

    // On prepare le paquet a envoyer

    out << (quint16) 0;
    out << message;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    socket->write(paquet);
}

void Network::connecte() {
    emit event(CONNECTE,"Connexion au serveur reussie");
}

void Network::deconnecte() {
    emit event(DECONNECTE,"Deconnecte du serveur");
}

void Network::erreurSocket(QAbstractSocket::SocketError erreur) {
    QString message;

    switch(erreur) {
    case QAbstractSocket::RemoteHostClosedError:
        message = "Vous avez ete deconnecte du serveur, veuillez vous reconnecter.";
        break;
    case QAbstractSocket::ConnectionRefusedError:
        message = "Connexion refusee par le serveur, veuillez reessayer plus tard.";
        break;
    case QAbstractSocket::HostNotFoundError:
        message = "Serveur introuvable, etes vous connecte a internet ?";
        break;
    default:
        message = "Erreur de connexion, veuillez reessayer plus tard.";
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

