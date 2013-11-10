#include <QApplication>

#include "gamewindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Q_INIT_RESOURCE(res);
    GameWindow game;
    game.show();

    return a.exec();
}
