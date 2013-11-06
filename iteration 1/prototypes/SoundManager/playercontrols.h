#ifndef PLAYERCONTROLS_H
#define PLAYERCONTROLS_H

#include <QMediaPlayer>
#include <QWidget>

class QAbstractButton;

class PlayerControls : public QWidget
{
    Q_OBJECT

public:
    PlayerControls(QWidget *parent = 0);

    QMediaPlayer::State state() const;
    qreal playbackRate() const;

public slots:
    void setState(QMediaPlayer::State state);

signals:
    void play();
    void pause();
    void stop();
    void next();
    void previous();

private slots:
    void playClicked();

private:
    QMediaPlayer::State playerState;
    QAbstractButton *playButton;
    QAbstractButton *stopButton;
    QAbstractButton *nextButton;
    QAbstractButton *previousButton;
};

#endif // PLAYERCONTROLS_H
