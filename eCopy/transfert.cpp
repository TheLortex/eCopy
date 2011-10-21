#include "transfert.h"

transfert::transfert(NetPass *gtw,int ft_type, QString user, QString peer)
{
    setupUi(this);
    m_ft_type = ft_type;
    m_gtw = gtw;
    m_user = user;
    m_peer = peer;

    switch(ft_type) {
    case FT_SEND:
        stackedWidget->setCurrentIndex(0);
        break;
    case FT_RECEIVE:
        stackedWidget->setCurrentIndex(1);
        setWindowTitle("Transfert de fichiers avec" + m_peer);
        break;
    }

    liste_ft = new QToolBox;
    zone_transferts->layout()->addWidget(liste_ft);
}

transfert::~transfert()
{
    for(int i=0;i<widgets_tranferts.size();i++) {
        delete widgets_tranferts[i];
    }
}

void transfert::on_choose_f_b_clicked()
{
    fileList << QFileDialog::getOpenFileNames(this,"Choisir les fichiers",getenv(ENV_HOME));
    majFileList();
}

void transfert::majFileList() {
    QStringListModel *modele = new QStringListModel(fileList);
    liste_fichiers->setModel(modele);
}

void transfert::on_liste_fichiers_doubleClicked(const QModelIndex &index)
{
    QVariant elementSelectionne = liste_fichiers->model()->data(index,Qt::DisplayRole);
    fileList.removeOne(elementSelectionne.toString());
    majFileList();
}

void transfert::on_envoi_b_clicked()
{
    QString liste;
    for(int i=0;i<fileList.size();i++) {
        QStringList temp = fileList[i].split(DIR_SYM);
        liste += temp.last();
        if(i!=fileList.size()-1)
            liste += "ede5526dz665g4e1z3c1cq354eg51evb6ef54h1j3se345gf86ez6zlareponseest42"; // separator
    }

    m_gtw->envoyer(m_peer,"FILE SEND "+QString::number(m_user.split(" ").size())+" "+m_user+" "+liste);
}

void transfert::addFiles(QStringList names) {
    if(QMessageBox::information(this,m_peer + " veut vous envoyer des fichiers !","Acceptez vous de recevoir les fichiers suivants: <br />"+names.join("<bt />"),QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes) {
        for(int i=0;i<names.size();i++) {
            ft_widget *transfert = new ft_widget();
            widgets_tranferts << transfert;
            liste_ft->addItem(transfert,names[i] + " 0%");
        }
    }
    else {
        // Ah ouai connard ! Ben pour la peine je vais te faire planter petit trou du cul
        while(42==42) {
            // Mouahahahhaha ça va bugguer :P
        }
        accept();
        emit quitte();
    }
}
