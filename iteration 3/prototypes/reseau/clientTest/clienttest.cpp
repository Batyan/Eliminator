#include "clienttest.h"
#include "ui_clienttest.h"

clientTest::clientTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientTest)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    hostName = "127.0.0.1";
    hostPort = 8080;

    message = "";
    messageSize = 0;

    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(on_error(QAbstractSocket::SocketError)));

    connectSocket();
}

clientTest::~clientTest()
{
    delete ui;
}

void clientTest::connectSocket() {
    socket->abort();
    socket->connectToHost(hostName,hostPort);

    connect(socket, SIGNAL(connected()),    this, SLOT(on_connected())      );
    connect(socket, SIGNAL(disconnected()), this, SLOT(on_disconnected())   );
    connect(socket, SIGNAL(readyRead()),    this, SLOT(on_readyRead())      );
}

void clientTest::sendMessage(MyWall * wall) {
    qDebug() << "Debut sendMessage";

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << wall->serial();
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    if(socket->write(block)==-1)
        qDebug() << "ERROR";
    qDebug() << block.size() - sizeof(qint16);
    qDebug() << "Fin sendMessage";
}

void clientTest::on_readyRead() {

    QDataStream msgTmp(this->socket);

    msgTmp.setVersion(QDataStream::Qt_4_0);

    qDebug() << "Reception message:entete";

    if (messageSize == 0)
    {
        if (this->socket->bytesAvailable() < (int)sizeof(quint16))
            return;

        msgTmp >> this->messageSize;
    }

    qDebug() << messageSize;
    qDebug() << "Reception message:corps";

    if (this->socket->bytesAvailable() < messageSize)
        return;

    QVariant variant(msgTmp);
    MyWall wall = variant.value<MyWall>();

    ui->xprint->setText(QString::number(wall.x));
    ui->yprint->setText(QString::number(wall.y));
    ui->typeprint->setText(QString::number(wall.type));

    messageSize = 0;
}

void clientTest::on_error(QAbstractSocket::SocketError socketError) {

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

void clientTest::on_connected() {
    qDebug() << "Connexion établie!";
}

void clientTest::on_disconnected() {
    qDebug() << "Connexion perdue.";
    socket->deleteLater();
}

void clientTest::on_sendbutton_clicked()
{
    MyWall wall(ui->xinput->value(),ui->yinput->value(),ui->typeinput->value());

    sendMessage(&wall);
}
