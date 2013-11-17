#ifndef MYSERVER_H
#define MYSERVER_H

#define PORT    8080

#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>

#include "myclient.h"
#include "mywall.h"

class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(qint16 port = PORT, QObject * parent = 0);

    void deconnexion(MyClient * client);
    void requestRender(MyWall * wall);
signals:

public slots:
    void newConnection();


private:
    QTcpServer * server;
    QList<MyClient *> clients;
    MyWall * wall;

    int writeOneClient(MyWall * wall, MyClient * client);
    int writeRestricted(MyWall * wall, QList<MyClient *> resClients);
};

#endif // MYSERVER_H
