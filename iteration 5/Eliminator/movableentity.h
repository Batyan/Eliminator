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
    int id; /*!< @brief Identifiant de l'objet movable. */
    int dirMove;  /*!< @brief Valeur de la direction du mouvement à faire. */
    int animFrame;  /*!< @brief Valeur de la frame d'animation à faire. */
    int animDelta;  /*!< @brief Valeur de la frame par second. */
    int animTime; /*!< @brief Vitesse que prendra une animation de déplacement dans le temps. */
    qreal speedWalking; /*!< @brief Vitesse de déplacement de l'object.*/
    SpriteImgMove * pSpriteMove; /*!< @brief Pointeur sur SpriteImgMove qui gère l'affichage d'une animation.*/
public:
    /**
     * @brief Constructeur MovableEntity.
     * @details On définie une MovableEntity, avec une position et une taille.
     */
    MovableEntity(qreal x, qreal y, int width, int height);

    /**
     * @brief fonction IsInCollision
     * @return Vrai si l'objet est en collision avec un autre.
     */
    bool IsInCollision();

    //! @brief getId
    int getId() const;
    //! @brief setId
    void setId(int value);

    //! @brief getDirMove
    int getDirMove() const;
    //! @brief setDirMove
    void setDirMove(int value);

    //! @brief getAnimFrame
    int getAnimFrame() const;
    //! @brief setAnimFrame
    void setAnimFrame(int value);

    //! @brief getAnimDelta
    int getAnimDelta() const;
    //! @brief setAnimDelta
    void setAnimDelta(int value);

    //! @brief getAnimTime
    int getAnimTime() const;
    //! @brief setAnimTime
    void setAnimTime(int value);

    //! @brief getSpeedWalking
    qreal getSpeedWalking() const;
    //! @brief setSpeedWalking
    void setSpeedWalking(const qreal &value);

    //! @brief getPSpriteMove
    SpriteImgMove *getPSpriteMove() const;
    //! @brief setPSpriteMove
    void setPSpriteMove(SpriteImgMove *value);

private:
    /**
     * @brief ifIcantMove
     * @return Vrai si l'objet est en collision du a un déplacement.
     */
    bool ifIcantMove(const QGraphicsItem * item);

    /**
     * @brief intersectItems
     * @return Vrai si l'objet "item" est en collision avec les deux points passé en parametre.
     */
    bool intersectItems(const QGraphicsItem * item, const QPointF& Point1, const QPointF & Point2);
};

#endif // MOVABLEENTITY_H
