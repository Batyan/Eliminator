
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

    /*On initialise un ennemie.*/
    NcpEnnemy * ennemy = new NcpEnnemy();
    /*On donne une cible à l'ennemie.*/
    ennemy->setTarget(player);

    /*On ajout l'ennemie dans la scène.*/
    //addItem(ennemy);
    /*On ajout le player dans la scène.*/

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

    /*On initialise un ennemie.*/
    NcpEnnemy * ennemy = new NcpEnnemy();
    /*On donne une cible à l'ennemie.*/
    ennemy->setTarget(player);

    /*On ajout l'ennemie dans la scène.*/
    //addItem(ennemy);
    /*On ajout le player dans la scène.*/
    addItem(player);

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

void LevelScene::movePlayer(int id, qreal xa, qreal ya)
{
    int i;

    for(i=0;i<otherPlayers.size();i++)
        if(otherPlayers[i]->id == id){
            otherPlayers[i]->pSpriteMove->setIsWalking(false);
            otherPlayers[i]->pSpriteMove->setIsLookingRight(false);
            otherPlayers[i]->pSpriteMove->setIsLookingLeft(false);
            otherPlayers[i]->pSpriteMove->setIsLookingDown(false);
            otherPlayers[i]->pSpriteMove->setIsLookingUp(false);
            if(xa == 0 && ya == 0){
                qDebug() << "TRUUUUUUUUUUUUUUUUUUUUUUE";
            }
            else{
                if(xa > 0){
                    otherPlayers[i]->pSpriteMove->setIsLookingRight(true);
                }

                if(xa < 0){
                     otherPlayers[i]->pSpriteMove->setIsLookingLeft(true);
                }

                if(ya > 0){
                    otherPlayers[i]->pSpriteMove->setIsLookingDown(true);
                }

                if(ya < 0){
                     otherPlayers[i]->pSpriteMove->setIsLookingUp(true);
                }

                otherPlayers[i]->pSpriteMove->setIsWalking(true);
            }


            qDebug() << "pwet" << i << id << xa << ya;
            break;
        }
}

void LevelScene::keyPressEvent(QKeyEvent *event)
{
    qreal ya=0,xa=0;
    if(event->key() == Qt::Key_Up){
        ya -= 2;
    }else if(event->key() == Qt::Key_Down){
        ya += 2;
    }else if(event->key() == Qt::Key_Left){
        xa -= 2;
    }else if(event->key() == Qt::Key_Right){
        xa += 2;
    }

    emit sendPos(xa,ya);

    qDebug() << "press";

    QGraphicsScene::keyPressEvent(event);
}

void LevelScene::keyReleaseEvent(QKeyEvent *event)
{
    qreal ya=0,xa=0;
    if(   event->key() == Qt::Key_Up
       || event->key() == Qt::Key_Down
       || event->key() == Qt::Key_Left
       || event->key() == Qt::Key_Right)
    {

    }

    emit sendPos(xa,ya);
    qDebug() << "press";

    QGraphicsScene::keyReleaseEvent(event);
}

