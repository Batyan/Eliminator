/**
 * @file cell.h
 * @author Yann Battista
 * @date 11/11/2013
 * @version 1.0
 * @brief Une cell est une case d'une map.
 * @details Une map est divisée en un certain nombre de case
 *          pour faciliter la detection des collisions
 *          et l'ajout de nouveaux éléments
 */

#ifndef CELL_H
#define CELL_H

#include "entity.h"

class Cell
{
public:
    Cell();

    Entity *getEntity();

    bool containsWall();

    Cell* getNext();

    void addEntity();

    Cell* getLast();

private:
    Cell* next;
    Entity* entity;
};

#endif // CELL_H
