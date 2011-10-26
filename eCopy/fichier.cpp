#include "fichier.h"

using namespace std;

Fichier::Fichier(int mode, QString path)
{
    m_mode = mode;
    m_chemin = path;

    if(m_mode == READ) {
        QString text = readFile();
        hash(text);
    }
}

QString Fichier::readFile() {
    ifstream fichierSortie(m_chemin.toChar(),ifstream::binary | ifstream::in);
    if(fichierSortie) {
        string ligne;     //Une variable pour stocker les lignes lues
        QString contenu;

        while(getline(fichierSortie, ligne))    //Tant qu'on n'est pas a la fin, on lit
        {
            contenu = contenu + QString(ligne.c_str());
        }
        return contenu;
    }
    else
        return "Erreur";
}

bool Fichier::write(QString texte) {
    ofstream fichierEntree(m_chemin.toChar(),ofstream::binary | ofstream::app);
    if(fichierEntree)
    {
        fichierEntree << texte.toChar();
        return true;
    }
    else
    {
        return false;
    }

}

void Fichier::hash(QString text) {
    QStringList liste;

    QString block = "";
    if(text.size() < HASH_SIZE) {
        liste << text;
    }
    else {
        for(int i=0;i<text.size();i++) {
            if((i%HASH_SIZE == 0)&&(i != 0)) {
                liste << block;
                block = "";
            }
            block += text[i];

            if(i == text.size()-1)
                liste << block;

        }
    }

    m_content = liste;
}
