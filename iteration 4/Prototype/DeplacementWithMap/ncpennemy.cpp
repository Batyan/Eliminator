/**
  *@file ncpennemy.cpp
  *@author Guillaume Rasolo
  *@date 25/11/2013
  *@version 1.0
  */


#include <QPainter>

#include "directionmove.h"
#include "spriteimgmove.h"
#include "ncpennemy.h"

NcpEnnemy::NcpEnnemy()
    :MovableEntity(qrand()%250+50,qrand()%150+50,DEFAULT_E_WIDTH,DEFAULT_E_HEIGHT),target(NULL)
{
    eSpriteMove = new SpriteImgMove(":res/Ennemy/default.png");

}

NcpEnnemy::NcpEnnemy(qreal x, qreal y, int width, int height, QString crustomPathSprite)
    :MovableEntity(x,y,width,height),target(NULL)
{
    if(crustomPathSprite.isNull()){
        eSpriteMove = new SpriteImgMove(":res/Ennemy/default.png");
    }else{
        eSpriteMove = new SpriteImgMove(crustomPathSprite);
    }
}

void NcpEnnemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);

    /*Gère l'affichage du player*/
    QRectF rec = boundingRect();
    QBrush brush (Qt::blue);
    if(isInCollision()){
        brush.setColor(Qt::red);
    }

    painter->fillRect(rec,brush);
    painter->drawRect(rec);
    eSpriteMove->render(0,0,getWidth(),getHeight(),painter,getDirMove(),getAnimFrame());
}

void NcpEnnemy::advance(int phase)
{

    if(!phase) return;

    setAnimDelta(getAnimDelta()+1);

    setAnimTime(getAnimTime()+ getSpeedWalking());
    if(getAnimDelta() >= getAnimTime()){
        setAnimFrame(getAnimFrame()+1);
        setAnimDelta(0);

        if(getAnimFrame() > DEFAULT_ANIME_FRAME){
            setAnimFrame(0);
        }
        findPathToTarget();
    }

    setAnimTime(DEFAULT_ANIME_E_TIME);
}

QRectF NcpEnnemy::boundingRect() const
{
    return QRectF (0,0,getWidth(),getHeight());
}

QPainterPath NcpEnnemy::shape() const
{
    QPainterPath path;
    path.addRect(0,0,getWidth(),getHeight());
    return path;
}

void NcpEnnemy::setTarget(Entity *t)
{
    target = t;
}

NcpEnnemy::~NcpEnnemy()
{
    delete this;
}

void NcpEnnemy::move(qreal xa, qreal ya)
{
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
    if(!IsInCollision()){
        setPos(mapToScene(xa,ya));
    }


}

void NcpEnnemy::findPathToTarget()
{

    if(target == NULL) return;
    qreal xa = 0, ya =0;


    if(getY() <= target->getY()){
        ya += getSpeedWalking();
    }

    if(getY() >= target->getY()){
        ya -= getSpeedWalking();
    }

    if(getX() <= target->getX()){
        xa += getSpeedWalking();
    }
    if(getX() >= target->getX()){
        xa -= getSpeedWalking();
    }

    if(xa != 0 || ya != 0){
        eSpriteMove->setIsWalking(true);
        move(xa,ya);
    }else{
        eSpriteMove->setIsWalking(false);
    }



}
