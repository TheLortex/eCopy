#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QtGui>
#include <QtNetwork>
#ifdef _WIN32
   // #include <winsock.h>
   // #include <MYSQL/mysql.h>
#else
    #include <mysql/mysql.h>
#endif

#include "ui_mainwindow.h"

#define BDD_HOST "127.0.0.1"
#define BDD_USER "root"
#define BDD_PASS "Posit52a"
#define WITH_MYSQL

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void envoyer(const QString &message,int dest);
    int getSocketIdByName(QString pseudo);
    void notify(QString mess) {etat->append(mess); }
    void writeOutput(QString text);
    void exec(QString cmd,int from);
    void majListe();
    void getUsers();

private slots:
    void nouvelleConnexion();
    void donneesRecues();
    void deconnexionClient();
    void act() {
        getUsers();
    }
    void readInputFile();


private:
    QTcpServer *serveur;
    QList<QTcpSocket *> clients;
    quint16 tailleMessage;
    QStringList m_pseudos;
    QStringList m_pass;
    QStringList m_co;
    QList<int> m_indexSock;

    QTimer *actUser;
    QTimer *actInputFile;
};

#endif // MAINWINDOW_H
