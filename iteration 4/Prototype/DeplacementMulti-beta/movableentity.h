/**
  *@file movableentity.h
  *@author Guillaume Rasolo
  *@date 25/11/2013
  *@version 1.0
  *@brief Contient la définition d'une Entity qui peut se déplacer.
  */

#ifndef MOVABLEENTITY_H
#define MOVABLEENTITY_H

#include "entity.h"
#include "spriteimgmove.h"

/**
 * @author Guillaume Rasolo
 * @version 2.0
 * @brief La classe MovableEntity hérite de Entity.\n
 * Contient la définition d'une MovableEntity.
 */
class MovableEntity : public Entity
{
private:
    int dirMove;  /*!< @brief Valeur de la direction du mouvement à faire. */
    int animFrame;  /*!< @brief Valeur de la frame d'animation à faire. */
    int animDelta;  /*!< @brief Valeur de la frame par second. */
    int animTime; /*!< @brief Vitesse que prendra une animation de déplacement dans le temps. */
    qreal speedWalking; /*!< @brief Vitesse de déplacement de l'object.*/
public:
    SpriteImgMove *pSpriteMove;

    MovableEntity(qreal x, qreal y, int width, int height);


    virtual ~MovableEntity();

    bool isInCollision();

    int getDirMove() const;
    void setDirMove(int value);

    int getAnimFrame() const;
    void setAnimFrame(int value);

    int getAnimDelta() const;
    void setAnimDelta(int value);

    int getAnimTime() const;
    void setAnimTime(int value);


    qreal getSpeedWalking() const;
    void setSpeedWalking(const qreal &value);

    int id = -1;

    bool IsInCollision();
private:
    bool ifIcantMove(const QGraphicsItem * item);
    bool intersectItems(const QGraphicsItem * item, const QPointF& Point1, const QPointF & Point2);
};

#endif // MOVABLEENTITY_H
