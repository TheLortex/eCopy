#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
#include "ui_chat.h"
#include "netpass.h"

class NetPass;

class chat : public QDialog, public Ui::chat
{
    Q_OBJECT

public:
    chat(NetPass* gateway,QString my_pseudo, QString peer,QString message="");
    ~chat();
    void ajouterMessage(QString message);
    QString getPeer() { return m_peer; }

private slots:
    void on_messageAEnvoyer_returnPressed();
    void on_envoyer_b_clicked();
    void termine();

signals:
    void quitte();

private:
    NetPass *m_gateway;

    QString m_peer;
    QString m_pseudo;
};

#endif // CHAT_H

