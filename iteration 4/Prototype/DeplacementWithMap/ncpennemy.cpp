#include <QPainter>

#include "directionmove.h"
#include "spriteimgmove.h"
#include "ncpennemy.h"

NcpEnnemy::NcpEnnemy()
    :MovableEntity(qrand()%250+50,qrand()%150+50,DEFAULT_E_WIDTH,DEFAULT_E_HEIGHT),
      target(NULL),type(1)
{
    chasingMode=false;
    detectionDistance = DEFAULT_AGGRESSIVE_ZONE_DISTANCE;
    setPSpriteMove(new SpriteImgMove(":res/Ennemy/1.png"));

}

NcpEnnemy::NcpEnnemy(qreal x, qreal y, int type)
    :MovableEntity(x,y,DEFAULT_E_WIDTH,DEFAULT_E_HEIGHT),
      target(NULL),type(type)
{
    chasingMode=false;
    detectionDistance = DEFAULT_AGGRESSIVE_ZONE_DISTANCE;
    setPSpriteMove(new SpriteImgMove(":res/Ennemy/"+ QString::number(type)+".png"));

}

void NcpEnnemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);
    getPSpriteMove()->render(0,0,getWidth(),getHeight(),painter,getDirMove(),getAnimFrame());
}

void NcpEnnemy::advance(int phase)
{
    if(!phase) return;

    if(!chasingMode){
        targetInAgressiveZone();
    }else{
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

void NcpEnnemy::move(qreal xa, qreal ya)
{
    /*Permet de prendre en charge la diagonale et
     *une meilleur detection de la collision qui en découle*/
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

   if(!IsInCollision()){
        setPos(mapToScene(xa,ya));
   }


}

void NcpEnnemy::findPathToTarget()
{

    if(target == NULL) return;
    qreal xa = 0, ya =0;

    if(getY() <= target->getY()){
        ya += getSpeedWalking() * type;
    }

    if(getY() >= target->getY()){
        ya -= getSpeedWalking() * type;
    }

    if(getX() <= target->getX()){
        xa += getSpeedWalking() * type;
    }
    if(getX() >= target->getX()){
        xa -= getSpeedWalking() * type;
    }


    if(xa != 0 || ya != 0){
        getPSpriteMove()->setIsWalking(true);
        move(xa,ya);
    }else{
        getPSpriteMove()->setIsWalking(false);
    }

}

void NcpEnnemy::targetInAgressiveZone()
{
    qreal dx, dy, sqrDist;
    qreal sqrDetectionDist = detectionDistance * detectionDistance;

    dx = target->x() - this->x();
    dy = target->y() - this->y();

    sqrDist = dx *dx + dy * dy;

    if(sqrDist < sqrDetectionDist){
        chasingMode = true;
    }
}
