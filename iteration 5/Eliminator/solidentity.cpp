#include "solidentity.h"

SolidEntity::SolidEntity()
    :Entity(-1,-1,-1,-1),id(NULL)
{
}

SolidEntity::SolidEntity(qreal x, qreal y, int width, int height, int *id)
    :Entity(x,y,width,height),id(id)
{
}

int *SolidEntity::getId() const
{
    return id;
}
