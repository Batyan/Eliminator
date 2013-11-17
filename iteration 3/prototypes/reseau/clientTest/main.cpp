#include "clienttest.h"
#include <QApplication>
#include "mywall.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    clientTest w;
    w.show();

    qRegisterMetaTypeStreamOperators<MyWall>("MyWall");

    return a.exec();
}
