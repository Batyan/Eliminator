#include <QKeyEvent>

#include "mur.h"
#include "ncpennemy.h"
#include "player.h"
#include "levelscene.h"

LevelScene::LevelScene()
    :QGraphicsScene(),levelId(1)
{
    /*On charge les Tilesets du jeu.*/
    tile = Tile();

    /*On construit le chemin d'un niveau*/
    path = Dpath + QString::number(1) + ".xml";

    /*On charge la map*/
    map = new XmlTiledMap(path);

    /*On definie une image de fond d'écran pour la vue d'affichage*/
    setBackgroundBrush(QPixmap(":/res/background/bg_"+ QString::number(1)+".png"));

    /*On recupère les dimensions de la map->*/
    widthTile = map->getNbTileWidthInMap();
    heightTile = map->getNbTileHeightInMap();

    /*On recupère les dimensions d'une tile.*/
    width = map->getWidthTileMap();
    height = map->getHeightTileMap();

    /*On charge le niveau.*/
    loadWorld();
}

LevelScene::LevelScene(int id)
    :QGraphicsScene(),levelId(id)
{
    /*On charge les Tilesets du jeu.*/
    tile = Tile();

    /*On construit le chemin d'un niveau*/
    path = Dpath + QString::number(id) + ".xml";

    /*On charge la map*/
    map = new XmlTiledMap(path);

    /*On definie une image de fond d'écran pour la vue d'affichage*/
    setBackgroundBrush(QPixmap(":/res/background/bg_"+ QString::number(id)+".png"));

    /*On recupère les dimensions de la map->*/
    widthTile = map->getNbTileWidthInMap();
    heightTile = map->getNbTileHeightInMap();

    /*On recupère les dimensions d'une tile.*/
    width = map->getWidthTileMap();
    height = map->getHeightTileMap();

    /*On charge le niveau.*/
    loadWorld();
}

void LevelScene::setLevel(int id)
{
    clear();
    path = Dpath + QString::number(id) + ".xml";
    map = new XmlTiledMap(path);

    setBackgroundBrush(QPixmap(":/res/background/bg_"+ QString::number(id)+".png"));

    widthTile = map->getNbTileWidthInMap();
    heightTile = map->getNbTileHeightInMap();

    width = map->getWidthTileMap();
    height = map->getHeightTileMap();

    loadWorld();

}

void LevelScene::clear()
{
    QList <QGraphicsItem*> itemList = items();
    ennemies.clear();
    while(!itemList.isEmpty()){
        removeItem(itemList.first());
        itemList = items();
    }
    QGraphicsScene::clear();
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

void LevelScene::keyPressEvent(QKeyEvent *event)
{
    QGraphicsScene::keyPressEvent(event);
    /* Permet de changer de niveau avec les touches F1 et F2*/
    if(event->key() == Qt::Key_F2){
        if(levelId <8){
            levelId++;
            setLevel(levelId);
        }
    }else if(event->key() == Qt::Key_F1){
        if(levelId >1){
            levelId--;
            setLevel(levelId);
        }
    }
    setFocusItem(player);

}

void LevelScene::loadWorld()
{
    /*Permet de charger un niveau et d'ajouter les objets à la scene.*/
    for(int x =0; x < widthTile;x++){
        for(int y =0; y < heightTile;y++){
            if(map->getTileId(x,y,"Collision") == 0)continue;
            else if(map->getTileId(x,y,"Collision") == 3991){
                ennemies.append(new NcpEnnemy(x*width,y*height,1));
                addItem(ennemies.last());
            }
            else if(map->getTileId(x,y,"Collision") == 3992){
                ennemies.append(new NcpEnnemy(x*width,y*height,2));
                addItem(ennemies.last());
            }
            else if(map->getTileId(x,y,"Collision") == 3993){
                ennemies.append(new NcpEnnemy(x*width,y*height,3));
                addItem(ennemies.last());
            }
            else if(map->getTileId(x,y,"Collision") == 3994){
                ennemies.append(new NcpEnnemy(x*width,y*height,4));
                addItem(ennemies.last());
            }
            else if(map->getTileId(x,y,"Collision") == 3995){
                ennemies.append(new NcpEnnemy(x*width,y*height,5));
                addItem(ennemies.last());
            }else if(map->getTileId(x,y,"Collision") == 3996){
                ennemies.append(new NcpEnnemy(x*width,y*height,6));
                addItem(ennemies.last());
            }else if(map->getTileId(x,y,"Collision") == 3997){
                ennemies.append(new NcpEnnemy(x*width,y*height,7));
                addItem(ennemies.last());
            }else if(map->getTileId(x,y,"Collision") == 3998){
                player = new Player(x*width,y*height);
            }
            else{
                addItem(new Mur(x*width,y*height,width,height,
                                tile.getCollision().at(
                                    map->getTileId(x,y,"Collision") - map->getLayerIndexTileMap("terrain"))));
            }
        }
    }

    //On donne le player comme cible à tous les ennemis du niveau.
    foreach(NcpEnnemy *e , ennemies){
        e->setTarget(player);
    }

    addItem(player);
}


void LevelScene::advance()
{
    /*On rafraîchie la scène, en indiquant aux objets
     qui possèdent la fonction de se mettre à jour. */
    QGraphicsScene::advance();

    /*On met à jour la scène.*/
    update();
}

