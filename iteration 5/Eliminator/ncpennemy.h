/**
 * @file ncpennemy.h
 * @author Guillaume Rasolo
 * @date 25/11/2013
 * @version 1.0
 * @brief Contient la définition d'un Ennemie.
 */

#ifndef NCPENNEMY_H
#define NCPENNEMY_H

#include "movableentity.h"

//! @def DEFAULT_E_WIDTH
//! @brief Correspond à la largeur par défaut que prendra l'ennemie.
#define DEFAULT_E_WIDTH 32

//! @def DEFAULT_E_HEIGHT
//! @brief Correspond à la hauteur par défaut que prendra l'ennemie.
#define DEFAULT_E_HEIGHT 32

//! @def DEFAULT_ANIME_E_TIME
//! @brief Correspond à la vitesse que prendra une animation de déplacement dans le temps.
#define DEFAULT_ANIME_E_TIME 8

//! @def DEFAULT_ANIME_FRAME
//! @brief Correspond au frame d'animation d'un ennemie.
#define DEFAULT_ANIME_FRAME 2

//! @def DEFAULT_AGGRESSIVE_ZONE_DISTANCE
//! @brief Correspond à la zone d'aggressivité d'un ennemie.
#define DEFAULT_AGGRESSIVE_ZONE_DISTANCE 32*15

class SpriteImgMove;

/**
 * @author Guillaume Rasolo
 * @version 3.0
 * @brief La classe NcpEnnemy  hérite de MovableEntity.\n
 *  Contient la définition d'un ennemie.
 */
class NcpEnnemy : public MovableEntity
{
private:
    qreal detectionDistance; /*!< @brief Distance de dectection d'un ennemie.*/
    bool chasingMode; /*!< @brief Permet d'indiquer si on est en chase d'une cible.*/
    Entity * target;/*!< @brief Pointeur une entity qui sera la cible de l'ennemi.*/
    int type; /*!< @brief Le type d'un ennemi.*/
public:
    /**
     * @brief Constructeur NcpEnnemy par défaut.
     */
    NcpEnnemy();

    /**
     * @brief Constructeur NcpEnnemy.
     */
    NcpEnnemy(qreal x, qreal y, int type = 1);

    /**
     * @brief Permet l'affichage de l'ennemie avec ces animations correspondantes.
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * @brief Permet le rafraîchissement de l'objet.
     */
    void advance(int phase);

    //! @brief boundingRect
    QRectF boundingRect()const;

    //! @brief shape
    QPainterPath shape() const;

    /**
     * @brief setTarget
     */
    void setTarget(Entity *t);

private:
    /**
     * @brief Gère le déplacement par rapport aux coordonnées x et y données.
     */
    void move(qreal xa, qreal ya);

    /**
     * @brief Permet de trouver un chemin vers la cible.
     */
    void findPathToTarget();

    /**
     * @brief Permet de calculer si la cible est dans la zone d'aggresivité.
     */
    void targetInAgressiveZone();
};

#endif // NCPENNEMY_H
