/**
 * @file map.h
 * @author Yann Battista
 * @date 11/11/2013
 * @version 1.0
 * @brief Contient la définition d'une map
 */

#ifndef MAP_H
#define MAP_H

#include "Cell.h"
#include "player.h"

class Player;

class Map
{
public:
    Map();
    Map(int width, int height);
    Cell* getCell(int i, int j);

    bool canMove(Player* p, QPointF pos);

    int getWidth();
    int getHeight();

private:
    QVector<Cell*> cells;

    int width;
    int height;
};

#endif // MAP_H
