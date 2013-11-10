#include "entity.h"


Entity::Entity(qreal x, qreal y, int width, int height)
    :QGraphicsItem(), eWidth(width), eHeight(height)
{
    setPos(x,y);
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
