#ifndef PLAYER_H
#define PLAYER_H

#include <QtWidgets>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class QAbstractItemView;
class QMediaPlayer;
class QPushButton;
class PlaylistModel;


class PlayerSound : public QWidget
{
    Q_OBJECT

private:
    QMediaPlayer * player;
    QMediaPlaylist * playlist;
    qint64 duration;
    QAbstractItemView *playlistView;
    PlaylistModel *playlistModel;

private slots:
    void open();
    void durationChanged(qint64 duration);

    void previousClicked();
    void addToPlaylist(const QStringList &fileNames);

public:
    PlayerSound(QWidget * parent =0);
    ~PlayerSound();
};

#endif // PLAYER_H
