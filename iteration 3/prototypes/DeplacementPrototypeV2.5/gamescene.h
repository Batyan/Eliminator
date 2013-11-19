/**
 * @file gamescene.h
 * @author Guillaume Rasolo
 * @date 08/11/2013
 * @version 1.0
 * @brief GameScene s'occupe des objects.
 * @details Elle s'occupe du comportement des objets quelles contient.
 * \n Le rafraichissement, leur position par rapport à la scène
 * et l'envoie des évènements destinés aux objets y sont gérés.
 */

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>

class Entity;

/**
 * @author Guillaume Rasolo
 * @version 1.0
 * @brief La classe GameScene hérite de QGraphicsScene.\n
 * GameScene s'occupe des objets.
 * @details QGraphicsScene est une classe interne de Qt.
 */
class GameScene: public QGraphicsScene
{
    Q_OBJECT
private:
    Entity* player; /*!< @brief Pointeur d'un object Entity.*/
public:
    /**
     * @brief Constructeur GameScene.
     * @details Constructeur par défaut, qui initialisera la scène.
     */
    GameScene();
protected:
    /**
     * @brief mousePressEvent
     * @param event Événement souris.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    /**
     * @brief mouseReleaseEvent
     * @param event Événement souris.
     */
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public slots:
    /**
     * @brief fonction advance
     * @details la fonction advance() est appelée, lorsque l'on reçoi le signal timeout
     * du timer pour rafraîchir la scène.
     */
    void advance();

};

#endif // GAMESCENE_H
