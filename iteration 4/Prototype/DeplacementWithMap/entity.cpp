/**
  *@file entity.cpp
  *@author Guillaume Rasolo
  *@date 08/11/2013
  *@version 1.0
  */

#include <QGraphicsScene>
#include "entity.h"

Entity::Entity(qreal x, qreal y, int width, int height)
    :QGraphicsItem(), eWidth(width), eHeight(height)
{
    /* On définie la position de l'entity par rapport à sa scène.*/
    setPos(x,y);
}

bool Entity::isCollision()
{
    if(!scene()->collidingItems(this).isEmpty()){
           return true;
    }

    return false;
}

int Entity::getWidth() const
{
    return eWidth;
}

int Entity::getHeight() const
{
    return eHeight;
}

qreal Entity::getX() const
{
    return x();
}

qreal Entity::getY() const
{
    return y();
}

Entity::~Entity(){}
