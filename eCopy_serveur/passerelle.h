#ifndef PASSERELLE_H
#define PASSERELLE_H

#include <QtNetwork>
#include <QMessageBox>
#include <QLabel>
#include <QObject>

#define PASSERELLE_PORT 2012

struct Message {
    bool demande;
    int index;
    QString pseudo,message;
};



class passerelle : public QObject
{
    Q_OBJECT
public:
    passerelle();
    ~passerelle();
    void envoyer(const QString &message,int dest);
    void askByFile(QString pseudo);
    void actInFile();

public slots:
    void nouvelleConnexion();
    void donneesRecues();
    void deconnexionClient();

    void actQueue();

private:
    QTcpServer *serveur;
    QList<QTcpSocket *> clients;
    quint32 tailleMessage;
    QQueue<Message> m_toSend;
    QTimer *m_watchQueue;
};

#endif // PASSERELLE_H
