/*
 * @File : gamescene.cpp
 * @Author: Guillaume Rasolo
 *
 */


#include <QTimer>
#include <QDebug>

#include "gamescene.h"
#include "ncp.h"

/**
 * @brief GameScene::GameScene
 * @description: On cree un joueur et des ncps qui seront ajouté dans la scene.
 *
 */
GameScene::GameScene()
    : QGraphicsScene()
{
    player =new PlayerSound();
    addItem(player);
    addItem(new Ncp());
    addItem(new Ncp("01"));
    addItem(new Ncp("02"));
    addItem(new Ncp("03"));
    addItem(new Ncp("04"));
    addItem(new Ncp("05"));
    addItem(new Ncp("06"));
    addItem(new Ncp("07"));
    setItemIndexMethod(QGraphicsScene::NoIndex);
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

