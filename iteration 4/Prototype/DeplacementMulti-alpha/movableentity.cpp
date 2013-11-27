/**
  *@file movableentity.cpp
  *@author Guillaume Rasolo
  *@date 25/11/2013
  *@version 1.0
  */

#include "movableentity.h"

MovableEntity::MovableEntity(qreal x, qreal y, int width, int height)
    :Entity(x,y,width,height),dirMove(0),animFrame(15),speedWalking(2)
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

MovableEntity::~MovableEntity(){}

bool MovableEntity::isInCollision()
{
    if(Entity::isCollision()){
           return true;
    }

    return false;

}
