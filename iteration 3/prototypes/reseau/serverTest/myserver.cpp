#include "myserver.h"
#include <QDebug>

/*
 * GUIEU CHRISTOPHE
 */

/*!
 * \brief MyServer::MyServer
 * \param parent
 * Création d'un serveur sur le port 8080 par défaut.
 * On y genera aussi l'unique map actuelle.
 */

MyServer::MyServer(qint16 port, QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);

    /*Callback de connexion*/
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::LocalHost,port)) {
        qDebug() << "Impossible de lancer le serveur.";
    }
    else {
        qDebug() << "Serveur lance sur le port" << port;
    }
}

/*!
 * \brief MyServer::newConnection
 * Cette fonction est appellee lors d'une nouvelle connexion.
 * Elle créée un nouveau MyClient avec la socket de service créée par
 *      QTcpServer :: nextPendingConnection();
 * puis ajoute le MyClient à la liste des clients connectés
 *      QList<MyClient *>Clients
 */

void MyServer::newConnection() {
    QTcpSocket * socket = server->nextPendingConnection();
    MyClient * client = new MyClient(socket,this,0);
    clients << client;

    qDebug() << "Nouveau client connecte. (" << clients.size() << ")";

    writeOneClient(new MyWall(10,10,10),client);
}

/*!
 * \brief MyServer::requestRender
 * \param req
 * C'est ici que le "moteur" du jeu en réseau sera mis en place.
 * Collision, vie, score ...
 */

void MyServer::requestRender(MyWall * wall) {

    qDebug() << "Debut request render";

    wall->print();

    writeRestricted(wall,clients);

    qDebug() << "Fin request render";
}

/*!
 * \brief MyServer::writeRestricted
 * \param message
 * \param resClients
 * \return 0 en cas de succes, -1 en cas d\'erreur.
 */

int MyServer::writeRestricted(MyWall * wall, QList<MyClient *> resclients) {
    int i;
    qDebug() << "Debut writeRestricted.";

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << wall->serial();
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    for(i=0; i < resclients.size(); i++)
        if(resclients[i]->getSocket()->write(block)==-1){
            qDebug() << "error write";
            return -1;
        }

    qDebug() << "Fin writeResctricted.";
    return 0;
}

int MyServer::writeOneClient(MyWall * wall, MyClient * client) {
    int i;
    qDebug() << "Debut writeRestricted.";

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << wall->serial();
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    if(client->getSocket()->write(block)==-1){
            qDebug() << "error write";
            return -1;
        }

    wall->print();
    qDebug() << block.size() - sizeof(quint16);
    qDebug() << "Fin writeResctricted.";
    return 0;
}

/*!
 * \brief MyServer::deconnexion
 * \param client
 * Gestion d'une deconnexion :
 * -la socket a ete fermee par MyClient
 * -extraction du client deconnecte de la liste
 */

void MyServer::deconnexion(MyClient * client) {
    clients.removeAt(clients.indexOf(client));
    qDebug() << "Destruction client. (" << clients.size() << ")";
}
