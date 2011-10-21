#ifndef NETPASS_H
#define NETPASS_H

#include <QObject>
#include <QtNetwork>

#include <mainwindow.h>

#define GATEWAY_IP "127.0.0.1"
#define GTW_PORT 2012

class NetPass : public QObject
{
    Q_OBJECT
public:
    NetPass();
    void connecter();
    void envoyer(QString message);
    void envoyer(QString pseudo,QString message);

public slots:
    void connecte();
    void deconnecte();
    void erreurSocket(QAbstractSocket::SocketError erreur);
    void messageRecu();
signals:
    void event(int,QString);
private:
    QTcpSocket *socket;
    quint32 tailleMessage;
};

#endif // NETPASS_H
