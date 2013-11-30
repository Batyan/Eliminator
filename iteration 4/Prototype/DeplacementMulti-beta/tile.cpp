/**
  *@file tile.cpp
  *@author Guillaume Rasolo
  *@date 25/11/2013
  *@version 1.0
  */


#include <QtCore/qmath.h>
#include <QPixmap>
#include "tile.h"

Tile::Tile()
    :size (TILE_SIZE_DEFAULT)
{

    QPixmap tileset =QPixmap(":res/TileMap/terrain.png");

    NbTileTerrain = tileset.width()/TILE_SIZE_DEFAULT;

    for(int i =0; i < NbTileTerrain;i++){
        for(int j =0; j < NbTileTerrain;j++){
            collision.push_back(new int[2]{j,i});
        }
    }

}

int Tile::getSizeTile() const
{
    return size;
}

QList<int*> Tile::getCollision() const
{
    return collision;
}
