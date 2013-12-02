/**
 * @file player.h
 * @author Guillaume Rasolo
 * @date 08/11/2013
 * @version 2.0
 * @brief Contient la définition d'un Player.
 * @details Un player est une Entity qui se déplace dans une scène grace aux
 * évènements clavier.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "movableentity.h"

//! @def DEFAULT_P_WIDTH
//! @brief Correspond à la largeur par défaut que prendra le player.
#define DEFAULT_P_WIDTH 32

//! @def DEFAULT_P_HEIGHT
//! @brief Correspond à la hauteur par défaut que prendra le player.
#define DEFAULT_P_HEIGHT 32

//! @def DEFAULT_ANIME_TIME
//! @brief Correspond à la vitesse que prendra une animation de déplacement dans le temps.
#define DEFAULT_ANIME_TIME 15

//! @def DEFAULT_ANIME_FRAME
//! @brief Correspond au frame d'animation du player.
#define DEFAULT_ANIME_FRAME 2

class SpriteImgMove;
/**
 * @author Guillaume Rasolo
 * @version 2.0
 * @brief La classe Player hérite de Entity.\n
 * Contient la définition d'un player.
 */
class Player: public MovableEntity
{
public:

    //! @brief Constructeur Player par défaut.
    Player();

    //! @brief Constructeur Player.
    Player(qreal x, qreal y, QString crustomPathSprite = NULL);


    //! @brief Permet l'affichage du player avec ces animations correspondantes.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


    //! @brief Permet le rafraîchissement de l'objet.
    void advance(int phase);

    //! @brief boundingRect
    QRectF boundingRect()const;

    //! @brief shape
    QPainterPath shape() const;

private:

    //! @brief Gère le déplacement par rapport aux coordonnées x et y données.
    void move(qreal xa, qreal ya);

protected:
    //! @brief keyPressEvent
    void keyPressEvent(QKeyEvent *event);
    //! @brief keyReleaseEvent
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // PLAYER_H
