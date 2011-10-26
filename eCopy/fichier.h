#ifndef FICHIER_H
#define FICHIER_H

#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>

#include <fstream>
#include <iostream>


#define WRITE 1
#define READ 2

#define HASH_SIZE 256

#define toChar() toStdString().c_str()

class Fichier
{
public:
    Fichier(int mode,QString path);
    bool write(QString texte);
    QStringList getContent() {return m_content;}
protected:
    QString readFile();
    void hash(QString texte);
private:
    QStringList m_content;
    int m_mode;
    QString m_chemin;

};

#endif // FICHIER_H
