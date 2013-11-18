/**
 * @file map.h
 * @author Yann Battista
 * @date 11/11/2013
 * @version 1.0
 * @brief Contient la définition d'une map
 */

#include "map.h"
#include <QDebug>

Map::Map(){
    width = 256;
    height = 256;
}

Map::Map(int width, int height)
{
    this->width = width;
    this->height = height;
}

int Map::getWidth()
{
    return this->width;
}

int Map::getHeight()
{
    return this->height;
}


bool Map::canMove(Player *p, QPointF pos)
{
    // On regarde en premier si on ne sort pas de la map.
    if (pos.x() < 0)
        return false;
    if (pos.y() < 0)
        return false;
    if (pos.x() + p->getWidth() > this->getWidth())
        return false;
    if (pos.y() + p->getHeight() > this->getHeight())
        return false;

    // Ensuite on regarde si il y a un mur
    /*if (getCell(pos.x(),                    pos.y()                 ).containsWall())
        return false;
    if (getCell(pos.x(),                    pos.y() + p->getHeight()).containsWall())
        return false;
    if (getCell(pos.x() + p->getWidth(),    pos.y()                 ).containsWall())
        return false;
    if (getCell(pos.x() + p->getWidth(),    pos.y() + p->getHeight()).containsWall())
        return false;
*/
    return true;
}
