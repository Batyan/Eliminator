#include "myclient.h"
#include "myserver.h"

#include <QDataStream>

/*
 *GUIEU CHRISTOPHE
 */

/*!
 * \brief MyClient::MyClient
 * \param socket
 * \param parent
 * \param id
 * Création de MyClient. Cela se resume principalement a la creation des signaux
 * pour celui ci.
 */

MyClient::MyClient(QTcpSocket * socket, QObject * parent, qint16 id)
{
    this->socket        = socket;
    this->messageSize   = 0;
    this->parent        = parent;
    this->id            = id;

    connect(socket, SIGNAL(readyRead()),    this, SLOT(read()));
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

/*!
 * \brief MyClient::read
 * Reception d un message : on recupere en premier l entete contenant la taille
 * du message. Puis le message lui meme.
 * On passe le message a requestRender() pour evaluation.
 */

void MyClient::read() {

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

    QVariant variant(msgTmp);
    MyWall wall(variant.value<MyWall>());

    wall.print();

    messageSize = 0;

    qobject_cast<MyServer *>(parent)->requestRender(&wall);
}

void MyClient::deconnexion() {
    qDebug() << "Fermeture de la socket";
    this->socket->close();
    qobject_cast<MyServer *>(parent)->deconnexion(this);
}
