/**
 * @file gamescene.cpp
 * @author Guillaume Rasolo
 * @date 08/11/2013
 * @version 1.0
 */
#include "player.h"
#include "entity.h"
#include "gamescene.h"


GameScene::GameScene()
    : QGraphicsScene()
{
    /*On initialise un player.*/
    player = new Player();

    /*On ajout l'objet dans la scène.*/
    addItem(player);
}


void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /*On renvoie les évènements souris à tous les objets de la scène.*/
    QGraphicsScene::mousePressEvent(event);

    /*On donne le focus des évènements à l'objet player.*/
    setFocusItem(player);
}


void GameScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
}


void GameScene::advance()
{
    /*On rafraîchie la scène, en indiquant aux objets
     qui possèdent la fonction de se mettre à jour. */
    QGraphicsScene::advance();

    /*On met à jour la scène.*/
    update();
}

