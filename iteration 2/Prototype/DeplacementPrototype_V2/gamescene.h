/*
 * @File : gamescene.h
 * @Author: Guillaume Rasolo
 * @Description: la classe GameScene contient tout les objects qui seront seront affiché.
 *
 */

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>


class Entity;

class GameScene: public QGraphicsScene
{
    Q_OBJECT
private:
    Entity* player;
public:
    GameScene();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public slots:
    void advance();

};

#endif // GAMESCENE_H
