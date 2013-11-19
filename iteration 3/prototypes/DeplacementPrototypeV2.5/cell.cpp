/**
 * @file cell.cpp
 * @author Yann Battista
 * @date 11/11/2013
 * @version 1.0
 */

#include "cell.h"

Cell::Cell()
{
   this->next = NULL;
}

Entity *Cell::getEntity()
{
    return this->entity;
}

bool Cell::containsWall()
{
    /*if (this->getEntity() == NULL)
        return false;*/
    return false;
}
/*
Cell *Cell::getNext()
{
    return this->next;
}

void Cell::addEntity(Entity entity)
{
    this->getLast()->next = entity;
}

Cell *Cell::getLast()
{
    if (next == NULL)
        return this;
    else
        return getLast(next);
}*/
