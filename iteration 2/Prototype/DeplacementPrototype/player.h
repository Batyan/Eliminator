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

class Player: public Entity
{
private:

    QPixmap sprite;
    bool isWalking;
    int animFrame;
    int dirMove;
    bool isLookingUp;
    bool isLookingLeft;
    bool isLookingRight;
    bool isLookingDown;

    int animDelta;
    int animTime;

    const int pImgDown[3][2] = {{ 0, 0 }, { 1, 0 }, { 2, 0 }};
    const int pImgLeft[3][2] = {{ 0, 1 }, { 1, 1 }, { 2, 1 }};
    const int pImgRight[3][2]= {{ 0, 2 }, { 1, 2 }, { 2, 2 }};
    const int pImgUp[3][2] = {{ 0, 3 }, { 1, 3 }, { 2, 3 }};

public:
    Player();
    Player(qreal x, qreal y, int width, int height, QPixmap crustomSprite = QPixmap());
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
