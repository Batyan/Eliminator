#include "gamemulti.h"

#include <QDebug>

GameMulti::GameMulti(LevelScene * levelscene,QString host, qint16 port, QObject * parent)
{
    GameMulti::levelscene = levelscene;

    socket = new QTcpSocket();

    hostName = host;
    hostPort = port;

    messageSize = 0;

    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(on_error(QAbstractSocket::SocketError)));

    socket->abort();
    socket->connectToHost(hostName,hostPort);

    connect(socket, SIGNAL(connected()),    this, SLOT(on_connected())      );
    connect(socket, SIGNAL(disconnected()), this, SLOT(on_disconnected())   );
    connect(socket, SIGNAL(readyRead()),    this, SLOT(on_readyRead())      );
}

void GameMulti::on_connected() {
    qDebug() << "Connexion établie!";

    if(!socket->waitForReadyRead(0)){
        qDebug() << "erreur id";
        on_disconnected();
    }
}

void GameMulti::on_disconnected() {
    qDebug() << "Connexion perdue.";
    socket->deleteLater();
    exit(0);
}

void GameMulti::on_error(QAbstractSocket::SocketError socketError) {

    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        qDebug() << "Hôte introuvable.";
        break;
    case QAbstractSocket::ConnectionRefusedError:
        qDebug() << "La connexion a été refusée."
                    "Vérifiez l'hôte et le port.";
        break;
    default:
        qDebug() << "Une erreur est intervenue:" << socket->errorString();
    }
}

void GameMulti::sendMessage(QVariant variant) {
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

void GameMulti::on_readyRead() {
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

    if(variant.canConvert<int>()){
        id = variant.value<int>();

        levelscene->addPlayer(id,true);

        qDebug() << id;

        GameMulti::localPlayer = levelscene->getLocalPlayer();
        PlayerLight pl(id,150,150,true);
        sendMessage(pl.serial());

        connect(levelscene, SIGNAL(sendPos(qreal, qreal, bool,bool,bool,bool,bool)), this, SLOT(on_tick(qreal,qreal,bool,bool,bool,bool,bool)));

    }
    if(variant.canConvert<PlayerLight>()){
        PlayerLight coopPlayer = variant.value<PlayerLight>();

        if(coopPlayer.isNew){
            levelscene->addPlayer(coopPlayer.id,false);
        }
        else
        {
            levelscene->movePlayer(coopPlayer.id,coopPlayer.x,coopPlayer.y,coopPlayer.isWalking,coopPlayer.isLookingRight,coopPlayer.isLookingLeft,coopPlayer.isLookingDown,coopPlayer.isLookingUp);
        }
    }

    messageSize = 0;
    in.resetStatus();

}

void GameMulti::on_tick(qreal x, qreal y, bool Walking, bool Right, bool Left, bool Down, bool Up)
{
    PlayerLight pl(id,x,y,false,Walking,Right,Left,Down,Up);
    sendMessage(pl.serial());
}
