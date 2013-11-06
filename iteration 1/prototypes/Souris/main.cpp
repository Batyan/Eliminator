#include "souris.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Souris w;
    w.show();

    return a.exec();
}
