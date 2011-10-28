#ifndef ENVOI_H
#define ENVOI_H

#include <QDialog>
#include <QFileDialog>
#include <QStringListModel>
#include <QToolBox>
#include "ui_transfert.h"
#include "netpass.h"
#include "ft_widget.h"
#include "fichier.h"

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
    void readytogo();
    void dataReceived(QString data);
    void sendNext();

protected:
    void majFileList();

private slots:
    void on_choose_f_b_clicked();
    void on_liste_fichiers_doubleClicked(const QModelIndex &index);

    void on_envoi_b_clicked();

    void on_quit_b_clicked() { accept(); emit quitte();}
    void on_quitter_b_clicked(){ accept();emit quitte();}

    void on_stop_all_clicked(){ accept();emit quitte();}

signals:
    void quitte();

private:
    int m_ft_type;
    NetPass *m_gtw;
    QString m_user;
    QString m_peer;

    QStringList fileList;
    QList<ft_widget *> widgets_tranferts;
    QToolBox* liste_ft;

    QList<Fichier *> tmp_files;
    int curFichier;
    int curPart;
};

#endif // ENVOI_H
