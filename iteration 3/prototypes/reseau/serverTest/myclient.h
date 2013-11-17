#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QTcpServer>
#include <QTcpSocket>

class MyClient : public QObject
{
    Q_OBJECT
public:
    MyClient(QTcpSocket * socket,QObject * parent,qint16 id);

    void    setMessageSize(qint16 messageSize);
    qint16  getMessageSize();
    void    resetMessageSize();
    bool    isMessageEmpty();
    QTcpSocket * getSocket();
public slots:
    void read();
    void deconnexion();

private:
    QObject * parent;
    QTcpSocket * socket;
    qint16 messageSize;
    qint16 id;
};

#endif // MYCLIENT_H
