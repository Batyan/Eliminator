/**
  *@file tile.h
  *@author Guillaume Rasolo
  *@date 25/11/2013
  *@version 1.0
  *@Permet la construction d'une matrice de Tile.
  */

#ifndef TILE_H
#define TILE_H

#include <QList>



#define TILE_SIZE_DEFAULT 32

/**
 * @author Guillaume Rasolo
 * @version 1.0
 * @brief La classe Tile.\n
 */
class Tile
{
private:
    int size; /*!< @brief taille d'une tile. */
    int NbTileTerrain;/*!< @brief Nombre total de tile dans la map. */
    QList<int*> collision;/*!< @brief List des objets tile.. */
public:
    /**
     * @brief Constructeur Tile
     */
    Tile();

    /**
     * @brief getSizeTile
     * @return la taille d'une tile.
     */
    int getSizeTile() const;

    /**
     * @brief getCollision
     * @return la liste des objets tile.
     */
    QList<int*> getCollision() const;

};

#endif // TILE_H
