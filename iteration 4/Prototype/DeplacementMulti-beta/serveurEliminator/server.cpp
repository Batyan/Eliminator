#include <QDebug>

#include "server.h"

server::server(quint16 port)
{
    messageSize = 0;
    tcpserver = new QTcpServer(this);

    if(!tcpserver->listen(QHostAddress::LocalHost,port)) {
        qDebug() << "Impossible de lancer le serveur.";
    }
    else {
        qDebug() << "Serveur lance sur le port" << port;
    }

    connect(tcpserver, SIGNAL(newConnection()),this, SLOT(on_connection()));

    idmax = 0;
}

void server::on_connection()
{
    QTcpSocket * socket = tcpserver->nextPendingConnection();
    PlayerLight pl(idmax,150,150,true);

    sockets[idmax] = socket;

    connect(socket, SIGNAL(readyRead()),    this,   SLOT(on_readyRead()));
    connect(socket, SIGNAL(disconnected()), this,   SLOT(on_deconnexion()));

    qDebug() << "Nouveau client connecte. (" << idmax << "," << sockets.size() << ")";

    QVariant variant(idmax);
    sendMessage(variant,socket);

    sendMessageOthers(pl.serial(),socket);
    idmax ++;
}

void server::on_deconnexion()
{
    int id;
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());

    if (socket == 0)
        return;

    id = sockets.key(socket);
    PlayerLight pl(id,0,0,false);
    sendMessageOthers(pl.serial(),socket);
    sockets.remove(id);
    qDebug() << "Deconnexion. (" << id << ")";
}

void server::on_readyRead()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    QDataStream in(socket);

    in.setVersion(QDataStream::Qt_4_0);

    if (socket == 0)
        return;

    if (messageSize == 0)
    {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> messageSize;
    }

    if (socket->bytesAvailable() < messageSize)
        return;

    QVariant variant(in);

    qDebug() << "readyRead";

    if(variant.canConvert<PlayerLight>()){
        variant.value<PlayerLight>().print();
        sendMessageOthers(variant,socket);
    }

    messageSize = 0;
    in.resetStatus();
}

void server::sendMessageOthers(QVariant variant,QTcpSocket * socket){
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << variant;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    foreach(int e, sockets.keys())
    {
        if(sockets[e] != socket)
            if(sockets[e]->write(block)==-1){
                qDebug() << "error write";
                return;
            }
    }
}

void server::sendMessage(QVariant variant, QTcpSocket * socket) {
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << variant;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    if(socket->write(block)==-1){
        qDebug() << "error write";
        return;
    }
}
