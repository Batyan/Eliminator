#include <QGraphicsScene>
#include "directionmove.h"
#include "movableentity.h"

MovableEntity::MovableEntity(qreal x, qreal y, int width, int height)
    :Entity(x,y,width,height),id(-1),dirMove(0),animFrame(15),speedWalking(2), pSpriteMove(NULL)
{
    /*On définie que player est un objet active*/
    setActive(true);
}


int MovableEntity::getDirMove() const
{
    return dirMove;
}

void MovableEntity::setDirMove(int value)
{
    dirMove = value;
}

int MovableEntity::getAnimFrame() const
{
    return animFrame;
}

void MovableEntity::setAnimFrame(int value)
{
    animFrame = value;
}

int MovableEntity::getAnimDelta() const
{
    return animDelta;
}

void MovableEntity::setAnimDelta(int value)
{
    animDelta = value;
}

int MovableEntity::getAnimTime() const
{
    return animTime;
}

void MovableEntity::setAnimTime(int value)
{
    animTime = value;
}

qreal MovableEntity::getSpeedWalking() const
{
    return speedWalking;
}

void MovableEntity::setSpeedWalking(const qreal &value)
{
    speedWalking = value;
}

bool MovableEntity::IsInCollision()
{
    bool iCantMove = false;
    if(isCollision()){
        QList<QGraphicsItem *> currentItems = scene()->collidingItems(this);

        if(currentItems.size() == 1){
            QGraphicsItem * item = currentItems.first();
            return ifIcantMove(item);
        }else{
            qreal cx = getX();
            qreal cy = getY();

            for(int i =0; i < currentItems.size();i++){
                if(getDirMove() == DIR_DOWN_MOVING){
                    QPointF footRight = QPointF(cx + 3,cy + getWidth()+5);
                    QPointF footLeft = QPointF(cx + getWidth() - 3,cy + getWidth()+5);

                    QGraphicsItem * item = currentItems.at(i);
                    if(((item->x() < footRight.x() && footRight.x() < item->x()+getWidth())
                        &&( item->y() < footRight.y() && footRight.y() < item->y() + getWidth()))
                            ||
                            ((item->x() < footLeft.x() && footLeft.x() < item->x()+getWidth())
                             &&( item->y() < footLeft.y() && footLeft.y() < item->y() + getWidth())))
                        iCantMove = true;
                }

                if(getDirMove() == DIR_UP_MOVING){
                    QPointF eyeRight = QPointF(cx + 3,cy - 5);
                    QPointF eyeLeft = QPointF(cx + getWidth() - 3,cy - 5);

                    QGraphicsItem * item = currentItems.at(i);
                    if(((item->x() < eyeRight.x() && eyeRight.x() < item->x()+getWidth())
                        &&( item->y() < eyeRight.y() && eyeRight.y() < item->y() + getWidth()))
                            ||
                            ((item->x() < eyeLeft.x() && eyeLeft.x() < item->x()+getWidth())
                             &&( item->y() < eyeLeft.y() && eyeLeft.y() < item->y() + getWidth())))
                        iCantMove = true;
                }

                if(getDirMove() == DIR_RIGHT_MOVING){
                    QPointF righthands = QPointF(cx + getWidth()+ 5,cy + 10);
                    QPointF rightfoots = QPointF(cx + getWidth()+ 5,cy + getWidth() - 2);

                    QGraphicsItem * item = currentItems.at(i);
                    if(((item->x() < righthands.x() && righthands.x() < item->x()+getWidth())
                        &&( item->y() < righthands.y() && righthands.y() < item->y() + getWidth()))
                            ||
                            ((item->x() < rightfoots.x() && rightfoots.x() < item->x()+getWidth())
                             &&( item->y() < rightfoots.y() && rightfoots.y() < item->y() + getWidth())))
                        iCantMove = true;

                }

                if(getDirMove() == DIR_LEFT_MOVING){
                    QPointF leftthands = QPointF(cx - 5,cy + 10);
                    QPointF leftfoots = QPointF(cx - 5,cy + getWidth() - 2);

                    QGraphicsItem * item = currentItems.at(i);
                    if(((item->x() < leftthands.x() && leftthands.x() < item->x()+getWidth())
                        &&( item->y() < leftthands.y() && leftthands.y() < item->y() + getWidth()))
                            ||
                            ((item->x() < leftfoots.x() && leftfoots.x() < item->x()+getWidth())
                             &&( item->y() < leftfoots.y() && leftfoots.y() < item->y() + getWidth())))
                        iCantMove = true;
                }
            }
        }
    }

    return iCantMove;
}

bool MovableEntity::ifIcantMove(const QGraphicsItem *item)
{
    qreal cx = getX();
    qreal cy = getY();

    if(getDirMove() == DIR_DOWN_MOVING){
        QPointF footRight = QPointF(cx + 3,cy + getWidth()+5);
        QPointF footLeft = QPointF(cx + getWidth() - 3,cy + getWidth()+5);

        return intersectItems(item,footRight,footLeft);
    }

    if(getDirMove() == DIR_UP_MOVING){
        QPointF eyeRight = QPointF(cx + 3,cy - 5);
        QPointF eyeLeft = QPointF(cx + getWidth() - 3,cy - 5);
        return intersectItems(item,eyeRight,eyeLeft);
    }

    if(getDirMove() == DIR_RIGHT_MOVING){
        QPointF rightHands = QPointF(cx + getWidth()+ 5,cy + 10);
        QPointF rightFoots = QPointF(cx + getWidth()+ 5,cy + getWidth() - 2);

        return intersectItems(item,rightHands,rightFoots);
    }

    if(getDirMove() == DIR_LEFT_MOVING){
        QPointF leftHands = QPointF(cx - 5,cy + 10);
        QPointF leftFoots = QPointF(cx - 5,cy + getWidth() - 2);
        return intersectItems(item,leftHands,leftFoots);
    }
    return false;
}

bool MovableEntity::intersectItems(const QGraphicsItem *item, const QPointF &Point1, const QPointF &Point2)
{
    if(((item->x() < Point1.x() && Point1.x() < item->x()+getWidth())
        &&( item->y() < Point1.y() && Point1.y() < item->y() + getWidth()))
            ||
            ((item->x() < Point2.x() && Point2.x() < item->x()+getWidth())
             &&( item->y() < Point2.y() && Point2.y() < item->y() + getWidth())))
        return true;

    return false;

}

SpriteImgMove *MovableEntity::getPSpriteMove() const
{
    return pSpriteMove;
}

void MovableEntity::setPSpriteMove(SpriteImgMove *value)
{
    pSpriteMove = value;
}


int MovableEntity::getId() const
{
    return id;
}

void MovableEntity::setId(int value)
{
    id = value;
}
