#ifndef ENVOI_H
#define ENVOI_H

#include <QDialog>
#include <QFileDialog>
#include <QStringListModel>
#include "ui_transfert.h"
#include "netpass.h"


#ifdef _WIN32
#define ENV_HOME "HOMEPATH"
#define DIR_SYM "\\"
#else
#define ENV_HOME "HOME"
#define DIR_SYM "/"
#endif

class NetPass;

class transfert : public QDialog, public Ui::transfert
{
    Q_OBJECT

public:
    transfert(NetPass *gtw,int ft_type,QString user="",QString peer="");
    ~transfert();
    QString getPeer(){return m_peer;}
    void addFiles(QStringList names);

protected:
    void majFileList();

private slots:
    void on_choose_f_b_clicked();
    void on_liste_fichiers_doubleClicked(const QModelIndex &index);

    void on_envoi_b_clicked();

    void on_quit_b_clicked() { accept(); emit quitte();}
    void on_quitter_b_clicked(){ accept();emit quitte();}

    void on_stop_all_clicked(){ /*m_gtw->envoyer(m_peer,"FILE STOP"); */accept();emit quitte();}

signals:
    void quitte();

private:
    int m_ft_type;
    NetPass *m_gtw;
    QString m_user;
    QString m_peer;

    QStringList fileList;
};

#endif // ENVOI_H
