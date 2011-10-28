#include "passerelle.h"

passerelle::passerelle() {
    serveur = new QTcpServer;
    tailleMessage = 0;

    QWidget* dial = new QWidget;
    dial->setWindowTitle("Passerelle de connexion");

    QVBoxLayout *layout = new QVBoxLayout;

    QLabel* label = new QLabel;

    if(serveur->listen(QHostAddress::Any,PASSERELLE_PORT)) {
        connect(serveur, SIGNAL(newConnection()), this, SLOT(nouvelleConnexion()));
        label->setText("Serveur demarre sur le port "+QString::number(PASSERELLE_PORT)+".");
    }
    else {
        label->setText("Le serveur de la passerelle n'a pas pu demarrer !");
    }

    layout->addWidget(label);

    etat = new QTextBrowser;

    layout->addWidget(etat,5);

    dial->setLayout(layout);
    dial->show();

    m_watchQueue = new QTimer;
    connect(m_watchQueue,SIGNAL(timeout()),this,SLOT(actQueue()));
    m_watchQueue->start(100);
}

passerelle::~passerelle() {
    delete m_watchQueue;
}

void passerelle::nouvelleConnexion()
{
    QTcpSocket *nouveauClient = serveur->nextPendingConnection();
    clients << nouveauClient;

    connect(nouveauClient, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(nouveauClient, SIGNAL(disconnected()), this, SLOT(deconnexionClient()));

}

void passerelle::donneesRecues()
{
   QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0)
        return;

    QDataStream in(socket);

    if (tailleMessage == 0)
    {
        if (socket->bytesAvailable() < (int)sizeof(quint32))
             return;

        in >> tailleMessage;
    }

    if (socket->bytesAvailable() < tailleMessage)
        return;

    QString message;
    in >> message;


    QStringList decomp = message.split(" ");
    QString pseudo = "";
    int taille = decomp[0].toInt();
    decomp.removeFirst();
    for(int i=0;i<taille;i++) {
        pseudo += decomp[0];
        decomp.removeFirst();
        if(i!=taille-1)
            pseudo += " ";
    }



    Message m;
    m.demande = false;
    m.index = -1;
    m.pseudo = pseudo;
    m.message = decomp.join(" ");

    m_toSend.append(m);

    //m_toSend.enqueue(m);

    tailleMessage = 0;
}

void passerelle::deconnexionClient()
{
    // On determine quel client se deconnecte
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // Si par hasard on n'a pas trouve le client a l'origine du signal, on arrete la methode
        return;

    clients.removeOne(socket);

    socket->deleteLater();
}

void passerelle::envoyer(const QString &message, int dest) {
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    out << (quint32) 0; // On ecrit 0 au debut du paquet pour reserver la place pour ecrire la taille
    out << message; // On ajoute le message a la suite
    out.device()->seek(0); // On se replace au debut du paquet
    out << (quint32) (paquet.size() - sizeof(quint32)); // On ecrase le 0 qu'on avait reserve par la longueur du message

    if(clients.size() > dest) {
        clients[dest]->write(paquet);
    }
}

void passerelle::actQueue() {
   // etat->append("------------------"+QString::number(m_toSend.size())+"--------------------");
    /*etat->append("------------------------------------------------");
    for(int i=0;i<m_toSend.size();i++) {
       etat->append("PSEUDO: " + m_toSend[i].pseudo + " ||| INDEX: "+QString::number(m_toSend[i].index) + " ||| DEMANDE: "+m_toSend[i].demande);
    }

    etat->append("------------------------------------------------");*/

    if(m_toSend.size() != 0) {
        if(m_toSend[0].index != -1) {
            if(m_toSend[0].index != -2) {
                clients[m_toSend[0].index]->waitForBytesWritten();
                envoyer(m_toSend[0].message,m_toSend[0].index);
                etat->append(m_toSend[0].message + " envoie a " + m_toSend[0].pseudo);
            }
            m_toSend.remove(0);
        }
        else if(m_toSend[0].demande == false) {
            bool found = false;

            for(int i=0;i<m_cache.size();i++) {
                if(m_toSend[0].pseudo == m_cache[i].first) {
                    m_toSend[0].index = m_cache[i].second;
                    found = true;
                }
            }

            if(!found) {
                askByFile(m_toSend[0].pseudo);
                m_toSend[0].demande = true;
            }
        }
        else {
            actInFile();
        }
    }
}

void passerelle::askByFile(QString pseudo) {
#ifdef _WIN32
    QFile file(".\\ask");
#else
    QFile file("./ask");
#endif

    if(file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
            out << pseudo << endl;
    }
}

void passerelle::actInFile() {
#ifdef _WIN32
    QFile file(".\\answer");
#else
    QFile file("./answer");
#endif
    QStringList lines;


    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString in = file.readAll();
        lines = in.split("\n");
    }
    else
        return;


    for(int i=0;i<lines.size();i++) {
        QStringList curLine = lines[i].split(" ");
        int curIndex = curLine[0].toInt();
        curLine.removeFirst();
        QString pseudo = curLine.join(" ");
       /* for(int i2 = 0;i2 < m_toSend.size();i2++) {
            if(m_toSend[i2].pseudo == pseudo) {
                if(curIndex == -1)
                    m_toSend[i2].index = -2;
                else
                    m_toSend[i2].index = curIndex;
            }
        }*/
        if(m_toSend[0].pseudo == pseudo) {
            if(curIndex == -1)
                m_toSend[0].index = -2;
            else
                m_toSend[0].index = curIndex;
        }

        if(curIndex != -1) {
            if(m_cache.size() < 100) {
                m_cache.append(QPair<QString,int>(pseudo,curIndex));
            } else {
                m_cache.remove(0);
                m_cache.append(QPair<QString,int>(pseudo,curIndex));
            }
        }

    }

    file.remove();
    file.close();
}


