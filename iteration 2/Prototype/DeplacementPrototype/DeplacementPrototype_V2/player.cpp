/*
 * @File : player.cpp
 * @Author: Guillaume Rasolo
 *
 */

#include <QGraphicsScene>
#include <QPainter>
#include <QKeyEvent>

#include "player.h"

#include "directionmove.h"
#include "spriteimgmove.h"

/**
 * @brief Player::Player
 */
Player::Player():
    Entity(150,150,DEFAULT_P_WIDTH,DEFAULT_P_HEIGHT),dirMove(0),
    animFrame(0),animDelta(0),animTime(DEFAULT_ANIME_TIME)

{

    pSpriteMove = new SpriteImgMove(":res/characters.png");

    setActive(true);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFocus();
}

Player::Player(qreal x, qreal y, int width, int height, QString crustomSprite)
    :Entity(x,y,width,height),dirMove(0),
      animFrame(0),animDelta(0),animTime(DEFAULT_ANIME_TIME)
{

    if(crustomSprite.isNull()){
         pSpriteMove = new SpriteImgMove(":res/characters.png");
    }else{
         pSpriteMove = new SpriteImgMove(crustomSprite);
    }

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

    pSpriteMove->render(x(),y(),getWidth(),getHeight(),painter,dirMove,animFrame);

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

    if(pSpriteMove->getIsLookingUp()){
        ya -= 1;
    }

    if(pSpriteMove->getIsLookingDown()){
        ya += 1;
    }

    if(pSpriteMove->getIsLookingLeft()){
        xa -= 1;
    }

    if(pSpriteMove->getIsLookingRight()){
        xa += 1;
    }

    if(xa != 0 || ya != 0){
        pSpriteMove->setIsWalking(true);
        move(xa,ya);
    }else{
        pSpriteMove->setIsWalking(false);
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
        pSpriteMove->setIsLookingUp(true);
    }
    if(event->key() == Qt::Key_Right){
        pSpriteMove->setIsLookingRight(true);
    }
    if(event->key() == Qt::Key_Left){
        pSpriteMove->setIsLookingLeft(true);
    }
    if(event->key() == Qt::Key_Down){
        pSpriteMove->setIsLookingDown(true);
    }



}

/**
 * @brief Player::keyReleaseEvent
 * @param event
 */
void Player::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        pSpriteMove->setIsLookingUp(false);
    }
    if(event->key() == Qt::Key_Right){
        pSpriteMove->setIsLookingRight(false);
    }
    if(event->key() == Qt::Key_Left){
        pSpriteMove->setIsLookingLeft(false);
    }
    if(event->key() == Qt::Key_Down){
        pSpriteMove->setIsLookingDown(false);
    }

}
