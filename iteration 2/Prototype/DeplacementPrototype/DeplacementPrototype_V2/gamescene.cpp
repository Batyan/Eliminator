/*
 * @File : gamescene.cpp
 * @Author: Guillaume Rasolo
 *
 */

#include "player.h"
#include "entity.h"
#include "gamescene.h"

/**
 * @brief GameScene::GameScene
 * @description: On cree un joueur qui seront ajouté dans la scene.
 *
 */
GameScene::GameScene()
    : QGraphicsScene()
{
    player = new Player();
    addItem(player);
}

/**
 * @brief GameScene::mousePressEvent
 * @param event
 * @description: gestion des inputs souris
 */

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
    setFocusItem(player);
}

/**
 * @brief GameScene::mouseReleaseEvent
 * @param event
 * @@description: gestion des output souris
 */
void GameScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
}

/**
 * @brief GameScene::advance
 * @description: le slot advance permet la mise a jour de la scene et des objects.
 */

void GameScene::advance()
{
    //mise a jour de la scene
    QGraphicsScene::advance();
    update();
}

