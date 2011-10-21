#include "chat.h"

chat::chat(NetPass *gateway, QString my_pseudo, QString peer, QString message) {
    setupUi(this);
    setWindowTitle("Discussion avec "+peer);

    m_gateway = gateway;

    if(message != "") {
        box_chat->append("<span>"+ message + "</span>");
    }

    m_peer = peer;
    m_pseudo = my_pseudo;

    connect(quitter,SIGNAL(clicked()),this,SLOT(termine()));
}



chat::~chat()
{
}


void chat::on_envoyer_b_clicked() {
    m_gateway->envoyer(m_peer,"MESSAGE "+ QString::number(m_pseudo.split(" ").size()) + " " + m_pseudo +" &lt;" + m_pseudo + "&gt; " + messageAEnvoyer->text());

    box_chat->append("<span>&lt;" + m_pseudo + "&gt; " + messageAEnvoyer->text()+"</span>");

    messageAEnvoyer->clear();
    messageAEnvoyer->setFocus();
}

void chat::termine() {
    accept();
    emit quitte();
}

void chat::on_messageAEnvoyer_returnPressed()
{
  //  on_envoyer_b_clicked();
}

void chat::ajouterMessage(QString message) {
    box_chat->append("<span>"+ message + "</span> <br />");
}
