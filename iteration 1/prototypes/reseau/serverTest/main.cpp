#include <QApplication>
#include "myserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyServer server;

    a.exec();
    return 0;
}
