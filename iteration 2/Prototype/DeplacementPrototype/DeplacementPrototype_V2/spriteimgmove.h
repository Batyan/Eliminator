#ifndef SPRITEIMGMOVE_H
#define SPRITEIMGMOVE_H

#include <QPainter>
#include <QPixmap>

class SpriteImgMove
{
private:
    QPixmap sprite;

    bool isWalking;
    bool isLookingUp;
    bool isLookingLeft;
    bool isLookingRight;
    bool isLookingDown;

    const int pImgDown[3][2] = {{ 0, 0 }, { 1, 0 }, { 2, 0 }};
    const int pImgLeft[3][2] = {{ 0, 1 }, { 1, 1 }, { 2, 1 }};
    const int pImgRight[3][2]= {{ 0, 2 }, { 1, 2 }, { 2, 2 }};
    const int pImgUp[3][2] = {{ 0, 3 }, { 1, 3 }, { 2, 3 }};
public:
    SpriteImgMove(QString pathSprite);
    ~SpriteImgMove();

    void render(qreal x, qreal y, int width, int height, QPainter *painter,int dirMove, int animFrame);

    bool getIsWalking() const;
    void setIsWalking(bool value);

    bool getIsLookingUp() const;
    void setIsLookingUp(bool value);

    bool getIsLookingLeft() const;
    void setIsLookingLeft(bool value);

    bool getIsLookingRight() const;
    void setIsLookingRight(bool value);

    bool getIsLookingDown() const;
    void setIsLookingDown(bool value);
};

#endif // SPRITEIMGMOVE_H
