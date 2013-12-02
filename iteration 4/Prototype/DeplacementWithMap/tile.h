/**
  *@file tile.h
  *@author Guillaume Rasolo
  *@date 25/11/2013
  *@version 1.0
  *@brief Permet la construction d'une matrice de Tile.
  */

#ifndef TILE_H
#define TILE_H

#include <QList>


//! @def TILE_SIZE_DEFAULT
//! @brief Correspond à la taille par défaut d'une tile.
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
    QList<int*> collision;/*!< @brief List des objets tile. */
public:

    //! @brief Constructeur Tile
    Tile();

    //! @brief getSizeTile
    int getSizeTile() const;

    //! @brief getCollision
    //! @return la liste des identifiant des objets collision.
    QList<int*> getCollision() const;

};

#endif // TILE_H
