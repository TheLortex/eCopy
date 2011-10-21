#ifndef CLIENT_H
#define CLIENT_H

#include <QtNetwork>
#include <QList>
#include <QObject>
#include "fichier.h"

class Client : public QObject
{
    Q_OBJECT
public:
    Client(QString id,QString ip);
  /*  void connecter();
    void envoyer(QString message);
    void envoyer(Fichier f);
    void envoyer(QList<Fichier> f);

public slots:
    void connecte();
    void deconnecte();
    void erreurSocket(QAbstractSocket::SocketError erreur);
    void donneesRecues();*/

signals:
    void event();
private:
    QString m_id;
    QString m_ip;

    QTcpSocket *socket;
    quint16 tailleMessage;
};

#endif // CLIENT_H
