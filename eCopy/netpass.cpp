#include "netpass.h"

NetPass::NetPass()
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(messageRecu()));
    connect(socket, SIGNAL(connected()), this, SLOT(connecte()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(deconnecte()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));

    tailleMessage = 0;
}

void NetPass::connecter() {
    socket->abort();
    socket->connectToHost(GATEWAY_IP,GTW_PORT);
    qDebug()<<"Connexion en cours !!";
}

void NetPass::envoyer(QString message) {

    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On prepare le paquet a envoyer

    qDebug()<<message;

    out << (quint32) 0;
    out << message;
    out.device()->seek(0);
    out << (quint32) (paquet.size() - sizeof(quint32));

    if(socket->isValid()) {
        socket->write(paquet);
    }
    else {
        qDebug()<<"Socket invalide !";
    }
}

void NetPass::envoyer(QString pseudo,QString message) {

    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On prepare le paquet à envoyer

    QString size = QString::number(pseudo.split(" ").size());

    message = size + " " + pseudo + " " + message;

    out << (quint32) 0;
    out << message;
    out.device()->seek(0);
    out << (quint32) (paquet.size() - sizeof(quint32));

    if(socket->isValid()) {
        socket->write(paquet);
    }
    else {
        qDebug()<<"Socket invalide !";
    }
}


void NetPass::connecte() {
    emit event(CONNECTE,"Connexion au serveur reussie");
}

void NetPass::deconnecte() {
    emit event(DECONNECTE,"Deconnecte du serveur");
}

void NetPass::erreurSocket(QAbstractSocket::SocketError erreur) {
    QString message;

    switch(erreur) {
    case QAbstractSocket::RemoteHostClosedError:
        message = "Vous avez ete deconnecte du serveur, veuillez vous reconnecter.";
        break;
    case QAbstractSocket::ConnectionRefusedError:
        message = "Connexion refusee par le serveur, veuillez réessayer plus tard.";
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

void NetPass::messageRecu() {
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

