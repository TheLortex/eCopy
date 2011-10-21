#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSystemTrayIcon>
#include <QMainWindow>
#include <QMessageBox>

#define CONNECTE 1
#define DECONNECTE 2
#define MESSAGE 3
#define ERREUR 4

#define FT_SEND 0
#define FT_RECEIVE 1

#include "ui_mainwindow.h"
#include "network.h"
#include "netpass.h"
#include "chat.h"
#include "transfert.h"


class QSystemTrayIcon;
class Network;
class NetP2P;
class Peer;
class NetPass;
class chat;
class transfert;

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool isReduit() { return m_reduit;}
    void systrayMessage(QString title,QString message);
    QString getPseudo() {return pseudo_l->text();}
protected:
    void logon();
    void traiterMessage(QString message);
private slots:
    void on_message_b_clicked();
    void on_actionReduire_triggered();
    void maximiser();
    void evenement(int type,QString message);
    void on_actionQuitter_triggered();
    void on_valider_b_clicked();    
    void on_actionSe_reconnecter_triggered();
    void on_chercher_b_clicked();
    void on_retour_b_clicked();
    void on_inscription_b_clicked();
    void systray_activated(QSystemTrayIcon::ActivationReason raison);

    void chatFini();
    void transfertFini();
    void gtw_event(int,QString);

    void on_fichier_b_clicked();

private:
    NetPass *gateway;
    Network *reseau;

    bool m_logged;
    QSystemTrayIcon* m_sticon;
    bool m_reduit;
    QRect m_dimensions;
    int m_port;

    QList<chat*> discussions;
    QList<transfert*> transferts;
};

#endif // MAINWINDOW_H





