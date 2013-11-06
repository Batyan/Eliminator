/*
 * @File : gamescene.h
 * @Author: Guillaume Rasolo
 * @Description: la classe GameScene contient tout les objects qui seront seront affiché.
 *
 */

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include "player.h"

class GameScene: public QGraphicsScene
{
    Q_OBJECT
private:
    PlayerSound* player;
public:
    GameScene();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public slots:
    void advance();

};

#endif // GAMESCENE_H
