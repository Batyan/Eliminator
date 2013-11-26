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
//! @details Initialiser à 32.
#define DEFAULT_E_WIDTH 32

//! @def DEFAULT_E_HEIGHT
//! @brief Correspond à la hauteur par défaut que prendra l'ennemie.
//! @details Initialiser à 32.
#define DEFAULT_E_HEIGHT 32

//! @def DEFAULT_ANIME_E_TIME
//! @brief Correspond à la vitesse que prendra une animation de déplacement dans le temps.
//! @details Initialiser à 8.
#define DEFAULT_ANIME_E_TIME 8

//! @def DEFAULT_ANIME_FRAME
//! @brief Correspond au frame d'animation d'un ennemie.
//! @details Initialiser à 2.
#define DEFAULT_ANIME_FRAME 2

class SpriteImgMove;

/**
 * @author Guillaume Rasolo
 * @brief La classe NcpEnnemy  hérite de MovableEntity.\n
 *  Contient la définition d'un ennemie.
 */
class NcpEnnemy : public MovableEntity
{
private:
    SpriteImgMove * eSpriteMove;/*!< @brief Pointeur sur SpriteImgMove
                                    qui gère l'affichage d'une animation.*/

    Entity * target;/*!< @brief Pointeur une entity qui sera la cible de l'ennemie.*/

public:
    /**
     * @brief Constructeur NcpEnnemy par défaut.
     */
    NcpEnnemy();

    /**
     * @brief Constructeur NcpEnnemy.
     * @param x Coordonnée x qui sera donner à l'ennemie.
     * @param y Coordonnée y qui sera donner à l'ennemie.
     * @param width Largeur qui sera donner à l'ennemie.
     * @param height Hauteur qui sera donner à l'ennemie.
     * @param crustomPathSprite Chemin du sprite qui correspond à l'ennemie. Initialiser à NULL.
     */
    NcpEnnemy(qreal x, qreal y, int width, int height, QString crustomPathSprite = NULL);

    /**
     * @brief Permet l'affichage de l'ennemie avec ces animations correspondantes.
     * @param painter Pointeur du painter de la fenêtre qui servira a dessiner.
     * @param option
     * @param widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * @brief Permet le rafraîchissement de l'objet.
     * @details Advance() est appelée que lorsque la scène lui dit de se rafraîchir.
     * @param phase
     */
    void advance(int phase);

    /**
     * @brief boundingRect
     * @return La dimension du rectangle.
     */
    QRectF boundingRect() const;

    /**
     * @brief shape
     * @return La forme de l'objet NcpEnnemy comme un QPainterPath en coordonnées locales.
     * @details La fonction est très utilisée pour les collisions.
     */
    QPainterPath shape() const;

    /**
     * @brief setTarget
     * @param t la cible.
     */
    void setTarget(Entity *t);

     //! @brief Destructeur ~NcpEnnemy.
    ~NcpEnnemy();

private:
    /**
     * @brief Gère le déplacement par rapport aux coordonnées x et y données.
     * @param xa Coordonnée x de déplacement.
     * @param ya Coordonnée y de déplacement.
     */
    void move(qreal xa, qreal ya);

    /**
     * @brief Permet de trouver un chemin vers la cible.
     */
    void findPathToTarget();
};

#endif // NCPENNEMY_H
