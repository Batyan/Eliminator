#ifndef MYSERVER_H
#define MYSERVER_H

#define PORT    8080

#include <QTcpServer>
#include <QTcpSocket>

#include "myclient.h"

class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject * parent = 0);

    void readnwrite(QString message);
    void deconnexion();

signals:

public slots:
    void newConnection();


private:
    QTcpServer * server;
    QList<MyClient *> clients;


};

#endif // MYSERVER_H
