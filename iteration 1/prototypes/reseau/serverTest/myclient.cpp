#include "myclient.h"
#include "myserver.h"

#include <QDataStream>

MyClient::MyClient(QTcpSocket * socket, QObject * parent, qint16 id)
{
    this->socket        = socket;
    this->messageSize   = 0;
    this->parent        = parent;
    this->id            = id;

    connect(socket, SIGNAL(readyRead()),    this, SLOT(readnwrite()));
    connect(socket, SIGNAL(disconnected()),  this, SLOT(deconnexion()));
}

void MyClient::setMessageSize(qint16 messageSize)
{
    this->messageSize = messageSize;
}

qint16 MyClient::getMessageSize()
{
    return this->messageSize;
}

QTcpSocket * MyClient::getSocket() {
    return socket;
}

void MyClient::resetMessageSize()
{
    this->messageSize = 0;
}

bool MyClient::isMessageEmpty()
{
    return this->messageSize == 0 ? true : false;
}

void MyClient::readnwrite() {

    socket->flush();
    QDataStream msgTmp(this->socket);

    msgTmp.setVersion(QDataStream::Qt_4_0);

    qDebug() << "Reception message:entete";

    if (isMessageEmpty())
    {
        if (this->socket->bytesAvailable() < (int)sizeof(quint16))
            return;

        msgTmp >> this->messageSize;
    }

    qDebug() << "Reception message:corps";

    if (this->socket->bytesAvailable() < messageSize)
        return;

    QString message;
    msgTmp >> message;

    qDebug() << message;

    messageSize = 0;

    qobject_cast<MyServer *>(parent)->readnwrite(message);
}

void MyClient::deconnexion() {
    qDebug() << "Fermeture de la socket";
    this->socket->close();
    qobject_cast<MyServer *>(parent)->deconnexion();
}
