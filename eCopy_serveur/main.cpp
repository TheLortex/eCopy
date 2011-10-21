#include <QtGui/QApplication>
#include "mainwindow.h"
#include "passerelle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w;
    passerelle *p;
    if(argc > 1) {
        p = new passerelle();
    }
    else {
        w = new MainWindow;
        w->show();
    }

    return a.exec();
}
