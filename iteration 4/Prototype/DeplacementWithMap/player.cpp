/**
  *@file player.cpp
  *@author Guillaume Rasolo
  *@date 08/11/2013
  *@version 1.0
  */


#include <QPainter>
#include <QKeyEvent>

#include "player.h"

#include "directionmove.h"
#include "spriteimgmove.h"


Player::Player()
    :MovableEntity(150,150,DEFAULT_P_WIDTH,DEFAULT_P_HEIGHT)

{
    /*On Donne un sprite par defaut à notre player*/
    pSpriteMove = new SpriteImgMove(":res/characters.png");

    /*On définie que player est focusable et peut resevoir des signaux envoyer par la scène.*/
    setFlag(QGraphicsItem::ItemIsFocusable);

    /*On définie que player est l'objet qui possède le focus des events envoyer par la scène.*/
    setFocus();
}

Player::Player(qreal x, qreal y, int width, int height, QString crustomPathSprite)
    :MovableEntity(x,y,width,height)
{

    /*On Donne un sprite à notre player,
       *si aucun chemin est définie c'est le sprite par défaut qui sera pris.*/
    if(crustomPathSprite.isNull()){
        pSpriteMove = new SpriteImgMove(":res/characters.png");
    }else{
        pSpriteMove = new SpriteImgMove(crustomPathSprite);
    }

    /*On définie que player est focusable et peut resevoir des signaux envoyer par la scène.*/
    setFlag(QGraphicsItem::ItemIsFocusable);

    /*On définie que player est un objet qui change de position dans la scène.*/
    setFlag(QGraphicsItem::ItemIsMovable);

    /*On définie que player est l'objet qui possède le focus des events envoyés par la scène.*/
    setFocus();

}


void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);

    /*Gère l'affichage du player*/
    pSpriteMove->render(0,0,getWidth(),getHeight(),painter,getDirMove(),getAnimFrame());

}

void Player::advance(int phase)
{
    if(!phase) return;

    qreal xa = 0, ya =0;

    if(pSpriteMove->getIsRunning()){
        setSpeedWalking(DEFAULT_SPEED_WALKING *3);
    }else{
        setSpeedWalking(DEFAULT_SPEED_WALKING);
    }

    setAnimDelta(getAnimDelta()+1);
    setAnimTime(getAnimTime()+ getSpeedWalking());
    /* On gère l'animation de déplacement */
    if(getAnimDelta() >= getAnimTime()){
        setAnimFrame(getAnimFrame()+1);
        setAnimDelta(0);

        if(getAnimFrame() > DEFAULT_ANIME_FRAME){
            setAnimFrame(0);
        }
    }

    /*On définie les coordonnées de déplacement
     *par rapport au sens où le player doit aller.*/
    if(pSpriteMove->getIsLookingUp()){
        ya -= getSpeedWalking();
    }else if(pSpriteMove->getIsLookingDown()){
        ya += getSpeedWalking();
    }else if(pSpriteMove->getIsLookingLeft()){
        xa -= getSpeedWalking();
    }else if(pSpriteMove->getIsLookingRight()){
        xa += getSpeedWalking();
    }

    /* On effectue le déplacement du player*/


    if(xa != 0 || ya != 0){
        pSpriteMove->setIsWalking(true);
        move(xa,ya);
    }else{
        pSpriteMove->setIsWalking(false);
    }


    setAnimTime(DEFAULT_ANIME_TIME);
}

QRectF Player::boundingRect() const
{
    return QRectF (0,0,getWidth(),getHeight());
}

QPainterPath Player::shape() const
{
    QPainterPath path;
    path.addRect(0,0,getWidth(),getHeight());
    return path;
}

Player::~Player()
{
    delete this;
}


void Player::move(qreal xa, qreal ya)
{
    /* On déplace le player de manière récursive tant que celui-ci veut bouger.*/
    if(xa != 0 && ya != 0){
        move(xa,0);
        move(0,ya);
        return;
    }

    /* On définie le sens de déplacement*/
    if(ya > 0){
        setDirMove(DIR_DOWN_MOVING);
    }

    if(ya < 0){
        setDirMove(DIR_UP_MOVING);
    }

    if(xa > 0){
        setDirMove(DIR_RIGHT_MOVING);
    }

    if(xa < 0){
        setDirMove(DIR_LEFT_MOVING);
    }

    /*On change les coordonnées de l'objet player par rapport à la scène.*/
    if(!IsInCollision())
        setPos(mapToScene(xa,ya));


}


void Player::keyPressEvent(QKeyEvent *event)
{
    /* On définie le sens où le player doit aller.*/
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

