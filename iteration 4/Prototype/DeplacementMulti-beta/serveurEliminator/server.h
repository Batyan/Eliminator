#ifndef SERVER_H
#define SERVER_H

#define PORT    5555
#define MAXCLI  10

#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QMap>

#include "playerlight.h"

class server : public QObject
{
    Q_OBJECT
public:
    server(quint16 port = PORT);
private slots:
    void on_connection();
    void on_deconnexion();
    void on_readyRead();
private:
    QTcpServer * tcpserver;
    QMap<int, QTcpSocket *> sockets;
    quint16 messageSize;
    int idmax;

    void sendMessage(QVariant variant, QTcpSocket * socket);
    void sendMessageOthers(QVariant variant, QTcpSocket * socket);
    void sendMessageAll(QVariant variant);
    void sendMove(PlayerLight pl);
    void sendCurrentPlayers(QTcpSocket * socket);
};

#endif // SERVER_H
