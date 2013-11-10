/*
 * @File : player.cpp
 * @Author: Guillaume Rasolo
 *
 */

#include <QGraphicsScene>
#include <QPainter>
#include <QKeyEvent>

#include "player.h"
#include "entity.h"
#include "directionmove.h"


/**
 * @brief Player::Player
 */
Player::Player():
    Entity(150,150,DEFAULT_P_WIDTH,DEFAULT_P_HEIGHT),isWalking(false),
    animFrame(0),isLookingLeft(false),isLookingRight(false),isLookingDown(false)

{
    isLookingUp = false;
    animDelta = dirMove = 0;
    sprite = QPixmap(":res/characters.png");
    animTime = DEFAULT_ANIME_TIME;

    setActive(true);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFocus();
}

Player::Player(qreal x, qreal y, int width, int height, QPixmap crustomSprite)
    :Entity(x,y,width,height),isWalking(false),
      animFrame(0),isLookingLeft(false),isLookingRight(false),isLookingDown(false)
{
    isLookingUp = false;
    animDelta = dirMove = 0;
    if(crustomSprite.isNull()){
        sprite = QPixmap(":res/characters.png");
    }else{
        sprite =crustomSprite;
    }

    animTime = DEFAULT_ANIME_TIME;

    setActive(true);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFocus();

}

/**
 * @brief Player::paint
 * @param painter
 * @param option
 * @param widget
 */
void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    Q_UNUSED(option);
    Q_UNUSED(widget);

    if(dirMove == DIR_DOWN_MOVING){
        if(isWalking){
            painter->drawPixmap(x(),y(),sprite,pImgDown[animFrame][0] * getWidth(),
                    pImgDown[animFrame][1] * getHeight(),getWidth(), getHeight());
        }else{
            painter->drawPixmap(x(),y(),sprite,pImgDown[0][0] * getWidth(),
                    pImgDown[0][1] * getHeight(),getWidth(), getHeight());
        }
    }

    if(dirMove == DIR_LEFT_MOVING){
        if(isWalking){
            painter->drawPixmap(x(),y(),sprite,pImgLeft[animFrame][0] * getWidth(),
                    pImgLeft[animFrame][1] * getHeight(),getWidth(), getHeight());
        }else{
            painter->drawPixmap(x(),y(),sprite,pImgLeft[0][0] * getWidth(),
                    pImgLeft[0][1] * getHeight(),getWidth(),getHeight());
        }
    }

    if(dirMove == DIR_UP_MOVING){
        if(isWalking){
            painter->drawPixmap(x(),y(),sprite,pImgUp[animFrame][0] * getWidth(),
                    pImgUp[animFrame][1] * getHeight(), getWidth(), getHeight());
        }else{
            painter->drawPixmap(x(),y(),sprite,pImgUp[0][0] * getWidth(),
                    pImgUp[0][1] * getHeight(),getWidth(),getHeight());
        }
    }

    if(dirMove == DIR_RIGHT_MOVING){
        if(isWalking){
            painter->drawPixmap(x(),y(),sprite,pImgRight[animFrame][0] * getWidth(),
                    pImgRight[animFrame][1] * getHeight(),getWidth(), getHeight());
        }else{
            painter->drawPixmap(x(),y(),sprite,pImgRight[0][0] * getWidth(),
                    pImgRight[0][1] * getHeight(),getWidth(),getHeight());
        }
    }

    QRectF rec = boundingRect();
    QBrush brush (Qt::green);
    if(!scene()->collidingItems(this).isEmpty()){
        brush.setColor(Qt::red);
    }

    painter->fillRect(rec,brush);
    painter->drawRect(rec);

}

/**
 * @brief Player::advance
 * @param phase
 */
void Player::advance(int phase)
{
    if(!phase) return;

    int xa = 0, ya =0;

    animDelta++;

    if(animDelta >= animTime){
        animFrame++;
        animDelta =0;

        if(animFrame > DEFAULT_ANIME_FRAME){
            animFrame =0;
        }
    }

    if(isLookingUp){
        ya -= 1;
    }

    if(isLookingDown){
        ya += 1;
    }

    if(isLookingLeft){
        xa -= 1;
    }

    if(isLookingRight){
        xa += 1;
    }

    if(xa != 0 || ya != 0){
        isWalking = true;
        move(xa,ya);
    }else{
        isWalking = false;
    }

}

/**
 * @brief Player::boundingRect
 * @return
 */
QRectF Player::boundingRect() const
{
    return QRectF (0,0,getWidth(),getHeight());
}

QPainterPath Player::shape() const
{
    QPainterPath path;
    path.addRect(-(getWidth()/2),-(getHeight()/2),getWidth(),getHeight());
    return path;
}

Player::~Player()
{
    delete this;
}

/**
 * @brief Player::move
 * @param xa
 * @param ya
 */
void Player::move(int xa, int ya)
{
    if(xa != 0 && ya != 0){
        move(xa,0);
        move(0,ya);
        return;
    }

    if(ya > 0){
        dirMove = DIR_DOWN_MOVING;
    }

    if(ya < 0){
        dirMove = DIR_UP_MOVING;
    }

    if(xa > 0){
        dirMove = DIR_RIGHT_MOVING;
    }

    if(xa < 0){
        dirMove =DIR_LEFT_MOVING;
    }

    setPos(mapToScene(xa,ya));

}


/**
 * @brief Player::keyPressEvent
 * @param event
 */
void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        isLookingUp = true;
    }
    if(event->key() == Qt::Key_Right){
        isLookingRight = true;
    }
    if(event->key() == Qt::Key_Left){
        isLookingLeft = true;
    }
    if(event->key() == Qt::Key_Down){
        isLookingDown = true;
    }


}

/**
 * @brief Player::keyReleaseEvent
 * @param event
 */
void Player::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        isLookingUp = false;
    }
    if(event->key() == Qt::Key_Right){
        isLookingRight = false;
    }
    if(event->key() == Qt::Key_Left){
        isLookingLeft = false;
    }
    if(event->key() == Qt::Key_Down){
        isLookingDown = false;
    }

}
