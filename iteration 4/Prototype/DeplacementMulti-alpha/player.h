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
private:
    SpriteImgMove * pSpriteMove; /*!< @brief Pointeur sur SpriteImgMove
                                    qui gère l'affichage d'une animation.*/
public:
    /**
     * @brief Constructeur Player par défaut.
     * @details On initialise le player avec les paramètres par défaut.
     */
    Player();

    /**
     * @brief Constructeur Player.
     * @param x Coordonnée x qui sera donner au player.
     * @param y Coordonnée y qui sera donner au player.
     * @param width Largeur qui sera donner au player.
     * @param height Hauteur qui sera donner au player.
     * @param crustomPathSprite Chemin du sprite qui correspond au player. Initialiser à NULL.
     */
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

    /**
     * @brief boundingRect
     * @return La dimension du rectangle.
     */
    QRectF boundingRect() const;

    /**
     * @brief shape
     * @return La forme de l'objet player comme un QPainterPath en coordonnées locales.
     * @details La fonction est très utilisée pour les collisions.
     */
    QPainterPath shape() const;

    //! @brief Destructeur ~Player.
    ~Player();

    /**
     * @brief Gère le déplacement par rapport aux coordonnées x et y données.
     * @param xa Coordonnée x de déplacement.
     * @param ya Coordonnée y de déplacement.
     */
    void move(qreal xa, qreal ya);

protected:
    /**
     * @brief keyPressEvent
     * @param event Événement clavier
     */
    void keyPressEvent(QKeyEvent *event);

    /**
     * @brief keyReleaseEvent
     * @param event Événement clavier
     */
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // PLAYER_H
