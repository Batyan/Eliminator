/**
  *@file solidentity.cpp
  *@author Guillaume Rasolo
  *@date 25/11/2013
  *@version 1.0
  */


#include "solidentity.h"

SolidEntity::SolidEntity()
    :Entity(-1,-1,-1,-1),id(NULL)
{
}

SolidEntity::SolidEntity(qreal x, qreal y, int width, int height, int *id)
    :Entity(x,y,width,height),id(id)
{
}

SolidEntity::~SolidEntity()
{
}

int *SolidEntity::getId() const
{
    return id;
}
