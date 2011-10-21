#ifndef FICHIER_H
#define FICHIER_H

#include <QtGui>

#define WRITE 1
#define READ 2

class Fichier
{
public:
    Fichier(int mode,QString path);
/*    void write(QString texte);
    QList<QString> getContent() {return m_content;}
protected:
    void readFile();*/
private:
    QList<QString> m_content;
    int m_mode;
    QString m_chemin;

};

#endif // FICHIER_H
