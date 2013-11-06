
#include "playersound.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*QMediaPlayer player;
    QString path = qApp->applicationDirPath();
    path.append("/sound/ETERNAL_DREAM.mp3");
    player.setMedia(QUrl::fromLocalFile(path));
    player.setVolume(50);

    player.play();
    */

    PlayerSound player;
    player.show();

    return a.exec();
}
