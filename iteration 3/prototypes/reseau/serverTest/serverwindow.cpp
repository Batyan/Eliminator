#include "serverwindow.h"
#include "ui_serverwindow.h"

ServerWindow::ServerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerWindow)
{
    ui->setupUi(this);
    server = new QTcpServer();
}

ServerWindow::~ServerWindow()
{
    delete ui;
}

void ServerWindow::on_startButton_clicked()
{
    server->listen(QHostAddress::LocalHost,8080);
}
