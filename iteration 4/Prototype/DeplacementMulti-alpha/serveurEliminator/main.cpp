#include <QCoreApplication>

#include "playerlight.h"
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    server tcpserver(5555);

    qRegisterMetaTypeStreamOperators<PlayerLight>("PlayerLight");

    return a.exec();
}
