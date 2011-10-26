#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);

    /*
      --------------------------------------------------------------------------------------------------------------------------------------------
      --------------------------------------------------------------------------------------------------------------------------------------------
      --------------------------------------------------------------------------------------------------------------------------------------------
      ------------------------- /!\ Le code suivant est le plus important du programme, ne pas le supprimer /!\ ----------------------------------
      --------------------------- Il fait des test pour savoir si les lois de l'Univers sont toujours actives ------------------------------------
      --------------------------------------------------------------------------------------------------------------------------------------------
      --------------------------------------------------------------------------------------------------------------------------------------------
      --------------------------------------------------------------------------------------------------------------------------------------------
      */

    int a_number = 6;
    int an_other_number = 7;

    int the_answer_to_life_the_universe_and_everything = a_number*an_other_number;

    QString my_name_is = "lucas";

    if((the_answer_to_life_the_universe_and_everything == 42)&&(1+1 == 2)&&(my_name_is == "lucas")) {
        // C'est bon tout est ok on peut continuer.
    }else {
        QMessageBox::critical(this,"Erreur critique","Un bug très important vient d'arriver, les lois de l'Univers sont chamboulees ! Pour savoir d'ou il vient, consultez le grand chamane.");
        qApp->quit();
    }

    /*
      --------------------------------------------------------------------------------------------------------------------------------------------
      --------------------------------------------------------------------------------------------------------------------------------------------
      --------------------------------------------------------------------------------------------------------------------------------------------
      --------------------------------------------------------------------------------------------------------------------------------------------
      --------------------------------------- Voilà c'est bon. -----------------------------------------------------------------------------------
      --------------------------------------------------------------------------------------------------------------------------------------------
      --------------------------------------------------------------------------------------------------------------------------------------------
      --------------------------------------------------------------------------------------------------------------------------------------------
      */


    reseau = new Network();
    gateway = new NetPass();
    connect(reseau,SIGNAL(event(int,QString)),this,SLOT(evenement(int,QString)));
    connect(gateway,SIGNAL(event(int,QString)),this,SLOT(gtw_event(int,QString)));
    reseau->connecter();
    gateway->connecter();

    m_logged = false;
    actionSe_reconnecter->setEnabled(false);
    valider_b->setEnabled(false);

    setWindowTitle(tr("eCopy - Client BETA 0.000000042000000001"));
    stackedWidget->setCurrentIndex(0);

    m_reduit = false;

}

MainWindow::~MainWindow()
{
    delete gateway;
    delete reseau;
}

void MainWindow::evenement(int type, QString message) {
    switch(type) {
    case CONNECTE:
        status->showMessage(message,10000);
        valider_b->setEnabled(true);
        actionSe_reconnecter->setEnabled(false);
        break;
    case DECONNECTE:
        status->showMessage(message,10000);
        valider_b->setEnabled(false);
        actionSe_reconnecter->setEnabled(true);
        stackedWidget->setCurrentIndex(0);
        break;
    case ERREUR:
        status->showMessage(message,10000);
        valider_b->setEnabled(false);
        actionSe_reconnecter->setEnabled(true);
        stackedWidget->setCurrentIndex(0);
        break;
    case MESSAGE:
        traiterMessage(message);
        break;
    }
}

void MainWindow::gtw_event(int type, QString message) {
    switch(type) {
    case CONNECTE:
        status->showMessage("Passerelle:"+message,10000);
        break;
    case DECONNECTE:

        status->showMessage("Passerelle:"+message,10000);
        valider_b->setEnabled(false);
        actionSe_reconnecter->setEnabled(true);
        stackedWidget->setCurrentIndex(0);

        break;
    case ERREUR:
        status->showMessage("Passerelle:"+message,10000);
        valider_b->setEnabled(false);
        actionSe_reconnecter->setEnabled(true);
        stackedWidget->setCurrentIndex(0);
        break;
    case MESSAGE:
        traiterMessage(message);
        break;
    }
}

void MainWindow::traiterMessage(QString message) {
    QStringList decomp = message.split(" ");
    if(decomp[0] == "LOGGED") {
        m_logged = true;
        info_l->setText("Bonjour "+pseudo_l->text()+" ! <br /> Que voulez-vous faire ?");
        stackedWidget->setCurrentIndex(2);
        status->showMessage("Identification reussie",10000);
    }
    else if(decomp[0]=="BAD") {
        if(decomp[1]=="PASSWORD"){
            status->showMessage("Erreur d'identification: Mauvais mot de passe",10000);
        }
        else if(decomp[1]=="ID"){
            status->showMessage("Erreur d'identification: Pseudo inconnu",10000);
        }
    }
    else if(decomp[0]=="FOUND") {
        if(decomp[1]=="0.0.0.0")  {
            found_ip->setText("0.0.0.0");
            found_co->setStyleSheet("color:red;");
            found_co->setText("Non");
            decomp.removeFirst();
            decomp.removeFirst();
            found_pseudo->setText(decomp.join(" "));


            message_b->setEnabled(false);
            fichier_b->setEnabled(false);
        }
        else {
            found_ip->setText(decomp[1]);
            found_co->setStyleSheet("color:green;");
            found_co->setText("Oui");
            decomp.removeFirst();
            decomp.removeFirst();
            found_pseudo->setText(decomp.join(" "));

            message_b->setEnabled(true);
            fichier_b->setEnabled(true);

        }
    }
    else if(decomp[0]=="NOT_FOUND") {
        found_pseudo->setText("Pseudo non trouve !");
        found_ip->setText("");
        found_co->setText("");
        message_b->setEnabled(false);
        fichier_b->setEnabled(false);
    }
    else if(decomp[0]=="MESSAGE") {
        qDebug()<<decomp.join(" ");
        decomp.removeFirst();
        int size = decomp[0].toInt();
        decomp.removeFirst();
        QString pseudo = "";
        for(int i=0;i<size;i++) {
            pseudo += decomp[0];
            decomp.removeFirst();
            if(i!=size-1)
                pseudo += " ";
        }


        QString message = decomp.join(" ");
        bool exist = false;
        for(int i=0;i<discussions.size();i++) {
            if(discussions[i]->getPeer() == pseudo) {
                discussions[i]->ajouterMessage(message);
                exist = true;
            }
        }

        if(!exist) {
            chat *c = new chat(gateway,pseudo_l->text(),pseudo,message);
            connect(c,SIGNAL(quitte()),this,SLOT(chatFini()));
            c->show();
            discussions << c;
        }
    }
    else if(decomp[0]=="FILE") {
        decomp.removeFirst();
        int taille = decomp[0].toInt();
        decomp.removeFirst();
        QString pseudo;
        for(int i=0;i<taille;i++) {
            pseudo += decomp[0];
            decomp.removeFirst();
            if(i!=taille-1)
                pseudo += " ";
        }
        if(decomp[0]=="SEND") {
            decomp.removeFirst();
            QString liste_fichiers_brut = decomp.join(" ");
            QStringList liste_fichiers = liste_fichiers_brut.split("ede5526dz665g4e1z3c1cq354eg51evb6ef54h1j3se345gf86ez6zlareponseest42");

            bool exist = false;
            for(int i=0;i<transferts.size();i++) {
                if(transferts[i]->getPeer() == pseudo) {
                    transferts[i]->addFiles(liste_fichiers);
                    exist = true;
                }
            }

            if(!exist) {
                transfert *t = new transfert(gateway,FT_RECEIVE,pseudo_l->text(), pseudo);
                connect(t,SIGNAL(quitte()),this,SLOT(transfertFini()));

                t->show();
                t->addFiles(liste_fichiers);
                transferts << t;
            }
        } else if(decomp[0]=="OK") {
            decomp.removeFirst();
            for(int i=0;i<envois.size();i++) {
                if(envois[i]->getPeer() == pseudo) {
                    envois[i]->readytogo();
                }
            }

        } else if(decomp[0]=="PART") {
            decomp.removeFirst();
            for(int i=0;i<transferts.size();i++) {
                if(transferts[i]->getPeer() == pseudo) {
                    transferts[i]->dataReceived(decomp.join(" "));
                }
            }
        }
    }
    else  {
        status->showMessage("Erreur inconnue",3000);
    }


}

void MainWindow::logon() {
    QByteArray mdp;
    QByteArray mdp_sha1 ;
    QString str_mdp_sha1 ;

    mdp.append( pass_l->text() );
    mdp_sha1 = QCryptographicHash::hash( mdp, QCryptographicHash::Sha1 );
    str_mdp_sha1 = mdp_sha1.toHex();
    reseau->envoyer("LOGON "+str_mdp_sha1+" "+pseudo_l->text());
}


void MainWindow::on_actionQuitter_triggered()
{
    qApp->quit();
}

void MainWindow::on_valider_b_clicked()
{
   logon();
}

void MainWindow::on_actionSe_reconnecter_triggered()
{
    reseau->connecter();
}

void MainWindow::on_inscription_b_clicked()
{
    stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_retour_b_clicked()
{
    stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_chercher_b_clicked()
{
    reseau->envoyer("SEARCH "+pseudo_search_l->text());
}


void MainWindow::on_actionReduire_triggered()
{
#ifdef _WIN32
    m_sticon = new QSystemTrayIcon(this); // on construit notre icône de notification

    // Creation du menu contextuel de notre icone
    QMenu* stmenu = new QMenu(this);

    QAction* actOuvrir = new QAction("Ouvrir",this);
    QAction* actQuitter = new QAction("Quitter",this);

    connect(actOuvrir,SIGNAL(triggered()),this,SLOT(maximiser()));
    connect(actQuitter,SIGNAL(triggered()),qApp,SLOT(quit()));

    stmenu->addAction(actOuvrir);
    stmenu->addAction(actQuitter);

    m_sticon->setContextMenu(stmenu); // On assigne le menu contextuel à l'icone de notification

    m_sticon->setIcon(QIcon(QPixmap(15,15)));

    connect(m_sticon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(systray_activated(QSystemTrayIcon::ActivationReason)));

    m_sticon->show(); // On affiche l'icone
    m_sticon->showMessage("Information","Je reste ici ..."); // On affiche une infobulle

    m_reduit = true;

    hide();
    m_dimensions = geometry();
    setGeometry(0,0,0,0);

    qApp->setQuitOnLastWindowClosed(false);
#else
    QMessageBox::warning(this,"Attention","Cette fonction n'a pas encore ete portee sous Linux ... Veuillez attendre qu'une mise à jour arrive (ou pas).");
#endif
}

void MainWindow::maximiser()
{
    delete m_sticon;
    m_reduit = false;
    qApp->setQuitOnLastWindowClosed(false);
    setGeometry(m_dimensions);
    show();
}

void MainWindow::systrayMessage(QString title, QString message) {
    m_sticon->showMessage(title,message);
}

void MainWindow::systray_activated(QSystemTrayIcon::ActivationReason raison) {
    if(raison == QSystemTrayIcon::DoubleClick) {
        maximiser();
    }
}

void MainWindow::on_message_b_clicked()
{
    chat *discut = new chat(gateway,pseudo_l->text(),found_pseudo->text());
    connect(discut,SIGNAL(quitte()),this,SLOT(chatFini()));
    discut->show();
    discussions << discut;
}

void MainWindow::chatFini() {
    chat *c = qobject_cast<chat *>(sender());
    discussions.removeOne(c);
    delete c;
}

void MainWindow::transfertFini() {
    transfert *t = qobject_cast<transfert *>(sender());
    if(!transferts.removeOne(t))
        envois.removeOne(t);
    delete t;
}


void MainWindow::on_fichier_b_clicked()
{
    transfert *send = new transfert(gateway,FT_SEND,pseudo_l->text(),found_pseudo->text());
    connect(send,SIGNAL(quitte()),this,SLOT(transfertFini()));
    send->show();
    envois << send;
}
