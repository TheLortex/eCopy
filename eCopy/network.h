#ifndef NETWORK_H
#define NETWORK_H

#include <QtNetwork/QtNetwork>
#include <QString>
#include <QObject>
#include "mainwindow.h"

#define SERVER_IP "127.0.0.1"
#define PORT 2011


class Network : public QObject
{
    Q_OBJECT
public:
    Network();
    void connecter();
    void envoyer(QString message);
    bool isConnected() {return socket->isValid();}

public slots:
    void connecte();
    void deconnecte();
    void erreurSocket(QAbstractSocket::SocketError erreur);
    void messageRecu();
signals:
    void event(int,QString);
private:
    QTcpSocket *socket;
    quint16 tailleMessage;

};

#endif // NETWORK_H
