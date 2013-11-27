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

    if(!socket->waitForReadyRead(3000)){
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

        connect(levelscene, SIGNAL(sendPos(qreal,qreal)), this, SLOT(on_tick(qreal,qreal)));

        /*connect(&timer, SIGNAL(timeout()), this, SLOT(on_tick()));
        timer.start(30);*/
    }
    if(variant.canConvert<PlayerLight>()){
        PlayerLight player = variant.value<PlayerLight>();

        if(player.isNew){
            levelscene->addPlayer(player.id,false);
        }
        else
        {
            player.print();
            levelscene->movePlayer(player.id,player.x,player.y);
        }
    }

    messageSize = 0;
}

void GameMulti::on_tick(qreal x, qreal y)
{
    qDebug() << "signal" << x << y;

    PlayerLight pl(id,x,y,false);

    sendMessage(pl.serial());
}

/*void GameMulti::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up   ||
       event->key() == Qt::Key_Right||
       event->key() == Qt::Key_Left ||
       event->key() == Qt::Key_Down){
        Entity * player = gamescene->getLocalPlayer();
        PlayerLight pl(id,player->getX(),player->getY(),false);
        sendMessage(pl.serial());
    }
}*/
