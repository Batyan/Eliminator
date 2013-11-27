#ifndef GAMEMULTI_H
#define GAMEMULTI_H

#include "player.h"
#include "playerlight.h"
#include "levelscene.h"

#include <QTcpSocket>
#include <QTimer>
#include <QtWidgets>
#include <QObject>

class GameMulti : public QObject
{
    Q_OBJECT
public:
    GameMulti(LevelScene * levelscene, QString host, qint16 port, QObject * parent = 0);
private:
    LevelScene * levelscene;

    QTcpSocket  * socket;
    QString     hostName;
    qint16      hostPort;
    qint16      messageSize;
    int id;

    MovableEntity * localPlayer;

    QTimer timer;

    void sendMessage(QVariant variant);
private slots:
    void on_connected();
    void on_disconnected();
    void on_readyRead();
    void on_error(QAbstractSocket::SocketError socketError);
    void on_tick();
};

#endif // GAMEMULTI_H
