
#include "spriteimgmove.h"
#include "directionmove.h"


SpriteImgMove::SpriteImgMove(QString pathSprite)
    :isWalking(false),isLookingUp (false),
      isLookingLeft(false),isLookingRight(false),isLookingDown(false)
{
    sprite = QPixmap(pathSprite);
}

SpriteImgMove::~SpriteImgMove()
{
    delete this;
}


void SpriteImgMove::render(qreal x, qreal y, int width, int height, QPainter *painter, int dirMove,int animFrame)
{
    if(dirMove == DIR_DOWN_MOVING){
        if(isWalking){
            painter->drawPixmap(x,y,sprite,pImgDown[animFrame][0] * width,
                    pImgDown[animFrame][1] * height,width, height);
        }else{
            painter->drawPixmap(x,y,sprite,pImgDown[0][0] * width,
                    pImgDown[0][1] * height,width, height);
        }
    }

    if(dirMove == DIR_LEFT_MOVING){
        if(isWalking){
            painter->drawPixmap(x,y,sprite,pImgLeft[animFrame][0] * width,
                    pImgLeft[animFrame][1] * height,width, height);
        }else{
            painter->drawPixmap(x,y,sprite,pImgLeft[0][0] * width,
                    pImgLeft[0][1] * height,width,height);
        }
    }

    if(dirMove == DIR_UP_MOVING){
        if(isWalking){
            painter->drawPixmap(x,y,sprite,pImgUp[animFrame][0] * width,
                    pImgUp[animFrame][1] * height, width, height);
        }else{
            painter->drawPixmap(x,y,sprite,pImgUp[0][0] * width,
                    pImgUp[0][1] * height,width,height);
        }
    }

    if(dirMove == DIR_RIGHT_MOVING){
        if(isWalking){
            painter->drawPixmap(x,y,sprite,pImgRight[animFrame][0] * width,
                    pImgRight[animFrame][1] * height,width, height);
        }else{
            painter->drawPixmap(x,y,sprite,pImgRight[0][0] * width,
                   pImgRight[0][1] * height,width,height);
        }
    }
}


bool SpriteImgMove::getIsWalking() const
{
    return isWalking;
}

void SpriteImgMove::setIsWalking(bool value)
{
    isWalking = value;
}

bool SpriteImgMove::getIsLookingUp() const
{
    return isLookingUp;
}

void SpriteImgMove::setIsLookingUp(bool value)
{
    isLookingUp = value;
}

bool SpriteImgMove::getIsLookingLeft() const
{
    return isLookingLeft;
}

void SpriteImgMove::setIsLookingLeft(bool value)
{
    isLookingLeft = value;
}

bool SpriteImgMove::getIsLookingRight() const
{
    return isLookingRight;
}

void SpriteImgMove::setIsLookingRight(bool value)
{
    isLookingRight = value;
}

bool SpriteImgMove::getIsLookingDown() const
{
    return isLookingDown;
}

void SpriteImgMove::setIsLookingDown(bool value)
{
    isLookingDown = value;
}
