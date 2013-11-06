/*
 * @File : player.h
 * @Author: Guillaume Rasolo
 * @Description: Contient la description d'un Player ayant la capacité de bouger et courir.
 *
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <QtCore>
#include <QPixmap>
#include <QGraphicsRectItem>

class PlayerSound: public QGraphicsRectItem
{
private:
    QPixmap m_sprite;
    bool m_isWalking;
    bool m_isUp, m_isLeft, m_isRight, m_isDown,m_isRun;
    int m_speedWalking;

    int m_animDelta;
    int m_animTime;
    int m_animFrame;
    int m_dir;
    int m_scalePlayer;

    int m_pWidth;
    int m_pHeight;

    int s_pImgDown[3][2];
    int s_pImgLeft[3][2];
    int s_pImgRight[3][2];
    int s_pImgUp[3][2];
public:
    PlayerSound();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    QRectF boundingRect() const;

    int getWidth() const;
    int getHeight() const;

private:
    void move(int xa, int ya);

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // PLAYER_H
