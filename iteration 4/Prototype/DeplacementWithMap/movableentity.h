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
    /**
     * @brief Constructeur MovableEntity.
     * @param x Coordonnée x qui sera donner à l'entity.
     * @param y Coordonnée y qui sera donner à l'entity.
     * @param width Largeur qui sera donner à l'entity.
     * @param height Hauteur qui sera donner à l'entity.
     * @details On définie une MovableEntity, avec une position et une taille.
     */
    MovableEntity(qreal x, qreal y, int width, int height);

    /**
     * @brief Desctucteur ~MovableEntity.
     */
    virtual ~MovableEntity();


    /**
     * @brief isInCollision
     * @return vrai si l'entity est en collision avec un autre objet.
     */
    bool isInCollision();


    /**
     * @brief getDirMove
     * @return
     */
    int getDirMove() const;

    /**
     * @brief setDirMove
     * @param value
     */
    void setDirMove(int value);

    /**
     * @brief getAnimFrame
     * @return
     */
    int getAnimFrame() const;

    /**
     * @brief setAnimFrame
     * @param value
     */
    void setAnimFrame(int value);

    /**
     * @brief getAnimDelta
     * @return
     */
    int getAnimDelta() const;

    /**
     * @brief setAnimDelta
     * @param value
     */
    void setAnimDelta(int value);

    /**
     * @brief getAnimTime
     * @return
     */
    int getAnimTime() const;

    /**
     * @brief setAnimTime
     * @param value
     */
    void setAnimTime(int value);

    /**
     * @brief getSpeedWalking
     * @return
     */
    qreal getSpeedWalking() const;

    /**
     * @brief setSpeedWalking
     * @param value
     */
    void setSpeedWalking(const qreal &value);
};

#endif // MOVABLEENTITY_H
