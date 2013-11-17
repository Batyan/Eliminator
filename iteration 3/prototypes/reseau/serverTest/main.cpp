#include <QApplication>
#include "myserver.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    qint16 port = PORT;
    MyServer server(port);

    qRegisterMetaTypeStreamOperators<MyWall>("MyWall");

    a.exec();
    return 0;
}
