/*
 * @File : player.h
 * @Author: Guillaume Rasolo
 * @Description: Contient la description d'un Player ayant la capacité de bouger et courir.
 *
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <QtCore>

#include "entity.h"

#define DEFAULT_P_WIDTH 32
#define DEFAULT_P_HEIGHT 32

#define DEFAULT_ANIME_TIME 15
#define DEFAULT_ANIME_FRAME 2

class SpriteImgMove;

class Player: public Entity
{
private:

    SpriteImgMove * pSpriteMove;

    int dirMove;
    int animFrame;
    int animDelta;
    int animTime;

public:
    Player();
    Player(qreal x, qreal y, int width, int height, QString crustomSprite = NULL);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    ~Player();

private:
    void move(int xa, int ya);

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // PLAYER_H
