#ifndef CLIENTTEST_H
#define CLIENTTEST_H

#include <QMainWindow>
#include <QTcpSocket>
#include "mywall.h"

namespace Ui {
class clientTest;
}

class clientTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit clientTest(QWidget *parent = 0);
    ~clientTest();

private slots:
    void on_connected();
    void on_disconnected();
    void on_readyRead();
    void on_error(QAbstractSocket::SocketError);
    void on_sendbutton_clicked();

private:
    Ui::clientTest *ui;
    QTcpSocket * socket;
    QString hostName;
    qint16 hostPort;
    QString message;
    qint16 messageSize;

    void connectSocket();
    void sendMessage(MyWall * wall);
};

#endif // CLIENTTEST_H
