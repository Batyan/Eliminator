/**
 * @file player.h
 * @author Guillaume Rasolo
 * @date 08/11/2013
 * @version 1.0
 * @brief Contient la définition d'un Player.
 * @details Un player est une Entity qui se déplace dans une scène grace aux
 * évènements clavier.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "movableentity.h"

//! @def DEFAULT_P_WIDTH
//! @brief Correspond à la largeur par défaut que prendra le player.
//! @details Initialiser à 32.
#define DEFAULT_P_WIDTH 32

//! @def DEFAULT_P_HEIGHT
//! @brief Correspond à la hauteur par défaut que prendra le player.
//! @details Initialiser à 32.
#define DEFAULT_P_HEIGHT 32

//! @def DEFAULT_ANIME_TIME
//! @brief Correspond à la vitesse que prendra une animation de déplacement dans le temps.
//! @details Initialiser à 15.
#define DEFAULT_ANIME_TIME 15

//! @def DEFAULT_ANIME_FRAME
//! @brief Correspond au frame d'animation du player.
//! @details Initialiser à 2.
#define DEFAULT_ANIME_FRAME 2

//! @def DEFAULT_ANIME_FRAME
//! @brief Correspond à la vitesse de deplacement du player.
//! @details Initialiser à 2.
#define DEFAULT_SPEED_WALKING 2

class SpriteImgMove;
/**
 * @author Guillaume Rasolo
 * @version 1.0
 * @brief La classe Player hérite de Entity.\n
 * Contient la définition d'un player.
 */
class Player: public MovableEntity
{

public:

    Player();
    Player(qreal x, qreal y, int width, int height, QString crustomPathSprite = NULL);

    /**
     * @brief Permet l'affichage du player avec ces animations correspondantes.
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
    QRectF boundingRect() const;
    QPainterPath shape() const;

    //! @brief Destructeur ~Player.
    ~Player();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    void move(qreal xa, qreal ya);
};

#endif // PLAYER_H
