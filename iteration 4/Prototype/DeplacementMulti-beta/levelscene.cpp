
#include "mur.h"
#include "ncpennemy.h"
#include "player.h"

#include "levelscene.h"
#include "spriteimgmove.h"

LevelScene::LevelScene()
    :QGraphicsScene()
{
    /*On charge les Tilesets du jeu.*/
    tile = Tile();

    /*On construit le chemin d'un niveau*/
    path = Dpath + QString::number(1) + ".xml";

    /*On charge la map*/
    map = new XmlTiledMap(path);


    /*On recupère les dimensions de la map->*/
    widthTile = map->getNbTileWidthInMap();
    heightTile = map->getNbTileHeightInMap();

    /*On recupère les dimensions d'une tile.*/
    width = map->getWidthTileMap();
    height = map->getHeightTileMap();

    /*On charge le niveau.*/
    loadWorld();

    /*On initialise un player.*/
    player = new Player();

}

LevelScene::LevelScene(int id)
    :QGraphicsScene()
{
    /*On charge les Tilesets du jeu.*/
    tile = Tile();

    /*On construit le chemin d'un niveau*/
    path = Dpath + QString::number(id) + ".xml";

    /*On charge la map*/
    map = new XmlTiledMap(path);


    /*On recupère les dimensions de la map->*/
    widthTile = map->getNbTileWidthInMap();
    heightTile = map->getNbTileHeightInMap();

    /*On recupère les dimensions d'une tile.*/
    width = map->getWidthTileMap();
    height = map->getHeightTileMap();

    /*On charge le niveau.*/
    loadWorld();

    /*On initialise un player.*/
    player = new Player();

}

void LevelScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /*On renvoie les évènements souris à tous les objets de la scène.*/
    QGraphicsScene::mousePressEvent(event);

    /*On donne le focus des évènements à l'objet player.*/
    setFocusItem(player);

}

void LevelScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
}

void LevelScene::loadWorld()
{
    /*Permet de charger un niveau et d'ajouter les objets à la scene.*/
    for(int x =0; x < widthTile;x++){
        for(int y =0; y < heightTile;y++){
            if(map->getTileId(x,y,"Collision") == 0)continue;
            addItem(new Mur(x*width,y*height,width,height,tile.getCollision().at(map->getTileId(x,y,"Collision") - map->getLayerIndexTileMap("terrain"))));
        }
    }
}

void LevelScene::advance()
{
    /*On rafraîchie la scène, en indiquant aux objets
     qui possèdent la fonction de se mettre à jour. */



    QGraphicsScene::advance();

    /*On met à jour la scène.*/
    update();
}

MovableEntity * LevelScene::getLocalPlayer()
{
    return LevelScene::player;
}

void LevelScene::addPlayer(int id,bool isLocal)
{
    Player * newplayer = new Player();
    newplayer->id = id;

    addItem(newplayer);

    if(isLocal)
        player = newplayer;
    else
        otherPlayers << newplayer;

    setFocusItem(player);

}

void LevelScene::removePlayer(int id)
{
    int i;

    for(i=0;i<otherPlayers.size();i++)
        if(otherPlayers[i]->id == id){
            removeItem(otherPlayers[i]);
            otherPlayers.removeAt(i);
            break;
        }
}


void LevelScene::movePlayer(int id,qreal x, qreal y, bool Walking, bool Right, bool Left, bool Down, bool Up)
{
    int i;

    for(i=0;i<otherPlayers.size();i++)
        if(otherPlayers[i]->id == id){
            otherPlayers[i]->setPos(x,y);
            otherPlayers[i]->pSpriteMove->setIsWalking(Walking);
            otherPlayers[i]->pSpriteMove->setIsLookingRight(Right);
            otherPlayers[i]->pSpriteMove->setIsLookingLeft(Left);
            otherPlayers[i]->pSpriteMove->setIsLookingDown(Down);
            otherPlayers[i]->pSpriteMove->setIsLookingUp(Up);

            break;
        }

}


void LevelScene::keyPressEvent(QKeyEvent *event)
{
     bool walking=false,up=false,down=false,left=false,right=false;

    if(event->isAutoRepeat()) return;

    if(event->key() == Qt::Key_Up){
        walking = true;
        up = true;
    }

    if(event->key() == Qt::Key_Down){
        walking = true;
        down = true;
    }

    if(event->key() == Qt::Key_Left){
        walking = true;
        left = true;
    }

    if(event->key() == Qt::Key_Right){
        walking = true;
        right = true;
    }

    emit sendPos(player->getX(),player->getY(),walking,right,left,down,up);
    QGraphicsScene::keyPressEvent(event);

}

void LevelScene::keyReleaseEvent(QKeyEvent *event)
{

    if(event->isAutoRepeat()) return;
    if(event->key() == Qt::Key_Up
            || event->key() == Qt::Key_Down
            || event->key() == Qt::Key_Left
            || event->key() == Qt::Key_Right){
        emit sendPos(player->getX(),player->getY(),false,false,false,false,false);
    }

    QGraphicsScene::keyReleaseEvent(event);

}

