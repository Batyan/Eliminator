#include "clienttest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    clientTest w;
    w.show();

    return a.exec();
}
