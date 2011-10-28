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
        setWindowTitle("Envoi de fichiers a " + m_peer);
        break;
    case FT_RECEIVE:
        stackedWidget->setCurrentIndex(1);
        setWindowTitle("Transfert de fichiers avec " + m_peer);
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

    m_gtw->envoyer(m_peer,"FILE "+QString::number(m_user.split(" ").size())+" "+m_user+" SEND "+liste);
}

void transfert::addFiles(QStringList names) {
    if(QMessageBox::information(this,m_peer + " veut vous envoyer des fichiers !","Acceptez vous de recevoir les fichiers suivants: <br />"+names.join("<bt />"),QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes) {
        QString directory = QFileDialog::getExistingDirectory(this,"Choisissez le dossier de destination",getenv(ENV_HOME));
        for(int i=0;i<names.size();i++) {
            ft_widget *transfert = new ft_widget();
            widgets_tranferts << transfert;
            liste_ft->addItem(transfert,names[i] + " 0%");

            Fichier *tmp_f = new Fichier(WRITE,directory + DIR_SYM + names[i]);
            tmp_files << tmp_f;
        }
        m_gtw->envoyer(m_peer,"FILE "+QString::number(m_user.split(" ").size())+" "+m_user+" OK");
    }
    else {
        // Ah ouai connard ! Ben pour la peine je vais te faire planter petit trou du cul
        while(42==42) {
            // Mouahahahhaha ça va bugguer :P
        }
        accept();
        emit quitte();
    }
    fileList += names;
}

void transfert::dataReceived(QString data) {
    QStringList decomp =  data.split(" ");
    int indexFichier = decomp[0].toInt();
    int index_cur_part = decomp[1].toInt();
    int total_part = decomp[2].toInt();
    decomp.removeFirst();
    decomp.removeFirst();
    decomp.removeFirst();
    QString content = decomp.join(" ");

    if(!tmp_files[indexFichier]->write(content)) {
        QMessageBox::critical(this,"Erreur fatale","Le système IO à totalement foiré ! Impossible d'écrire dans le fichier. A mon avis y'a un problème de permissions xD lol mdr ptdr TROLOLOLOLOL");
    }

    m_gtw->envoyer(m_peer,"FILE "+QString::number(m_user.split(" ").size())+" "+m_user+" NEXT");

    double coef = (index_cur_part+1) / (total_part*1.0);
    int pourcentage = coef*100;
    widgets_tranferts[indexFichier]->setPourcentage(pourcentage);
}

void transfert::readytogo() {
    stackedWidget->setCurrentIndex(1);

    for(int i=0;i < fileList.size();i++) {
        ft_widget *transfert = new ft_widget();
        widgets_tranferts << transfert;
        liste_ft->addItem(transfert,fileList[i] + " 0%");
    }

    curFichier = 0;
    curPart = 0;

    sendNext();
}

void transfert::sendNext() {
    if(fileList != fileList.size()) {
        Fichier file(READ,fileList[curFichier]);
        QStringList content = file.getContent();

        m_gtw->envoyer(m_peer,"FILE "+QString::number(m_user.split(" ").size())+" "+m_user+" PART "+ QString::number(curFichier) +" "+QString::number(curPart)+" "+QString::number(content.size())+" "+content[curPart]);
        m_gtw->getSocket()->waitForBytesWritten();
        double coef = (curPart+1) / (content.size()*1.0);
        int pourcentage = coef*100;
        widgets_tranferts[curFichier]->setPourcentage(pourcentage);
        widgets_tranferts[curFichier]->setWindowTitle(fileList[i] + " "+QString::number(pourcentage)+ "%");

        curPart++;
        if(curPart==content.size()) {
            curPart = 0;
            curFichier++;
        }
    }
    else {
        // Terminé.
    }
}
