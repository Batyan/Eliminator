#include "myserver.h"
#include <QDebug>

#include <QDataStream>

MyServer::MyServer(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);

    /*Callback de connexion*/
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::LocalHost,PORT)) {
        qDebug() << "Impossible de lancer le serveur.";
    }
    else {
        qDebug() << "Serveur lancé sur le port" << PORT;
    }
}

void MyServer::newConnection() {
    QTcpSocket * socket = server->nextPendingConnection();
    MyClient * client = new MyClient(socket,this,0);
    clients << client;

    /*connect(socket, SIGNAL(readyRead()), this, SLOT(readnwrite()));
    connect(socket, SIGNAL(deconnexion()), this, SLOT(deconnexion()));*/
}

void MyServer::readnwrite(QString message) {
    int i;
    qDebug() << "Message Recu";

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << message;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    for(i=0; i < clients.size(); i++)
        if(clients[i]->getSocket()->write(block)==-1)
            qDebug() << "ERROR";
}

void MyServer::deconnexion() {
    qDebug() << "Destruction MyClient";
}
