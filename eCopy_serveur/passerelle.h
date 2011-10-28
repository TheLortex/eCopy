#ifndef PASSERELLE_H
#define PASSERELLE_H

#include <QtNetwork>
#include <QMessageBox>
#include <QLabel>
#include <QObject>
#include <QVBoxLayout>
#include <QTextBrowser>

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

    //QQueue<Message> m_toSend;
    QVector<Message> m_toSend;
    QVector<QPair<QString,int> > m_cache;
    QTimer *m_watchQueue;

    QTextBrowser *etat;
};

#endif // PASSERELLE_H
