/**
  *@file spriteimgmove.h
  *@author Guillaume Rasolo
  *@date 08/11/2013
  *@version 1.0
  *@brief Contient la déscription des animations.
  *@details La classe SpriteImgMove permet de gérer les animations de déplacement.
  */

#ifndef SPRITEIMGMOVE_H
#define SPRITEIMGMOVE_H

#include <QPainter>
#include <QPixmap>

/**
 * @author Guillaume Rasolo
 * @version 1.0
 * @brief La classe SpriteImgMove
 * @details La classe s'occupe que de gérer les animations de
 * déplacement, garce aux informations qu'il reçoit de la classe qui l'appelle.
 */
class SpriteImgMove
{
private:
    QPixmap sprite; /*!< @brief Contient le sprite du personnage.*/

    bool isWalking; /*!< @brief Définie si le personnage bouge.*/
    bool isLookingUp; /*!< @brief Définie si le personnage regard en haut.*/
    bool isLookingLeft; /*!< @brief Définie si le personnage regard à gauche.*/
    bool isLookingRight; /*!< @brief Définie si le personnage regard à droite.*/
    bool isLookingDown; /*!< @brief Définie si le personnage regard en bas. */

    //! @brief On définie une matrice d'animation du déplacement en bas.
    const int pImgDown[3][2] = {{ 0, 0 }, { 1, 0 }, { 2, 0 }};

    //! @brief On définie une matrice d'animation du déplacement à gauche.
    const int pImgLeft[3][2] = {{ 0, 1 }, { 1, 1 }, { 2, 1 }};

    //! @brief On définie une matrice d'animation du déplacement à droite.
    const int pImgRight[3][2]= {{ 0, 2 }, { 1, 2 }, { 2, 2 }};

    //! @brief On définie une matrice d'animation du déplacement en haut.
    const int pImgUp[3][2] = {{ 0, 3 }, { 1, 3 }, { 2, 3 }};
public:
    /**
     * @brief Constructeur SpriteImgMove.
     * @param pathSprite Chemin du sprite qui correspond au personnage.
     */
    SpriteImgMove(QString pathSprite);

    /**
     * @brief Destructeur ~SpriteImgMove
     */
    ~SpriteImgMove();

    /**
     * @brief Permet de dessiner l'animation du sprite du personnage.
     * @param x Coordonnée x de la position.
     * @param y Coordonnée y de la position.
     * @param width Largeur du rectangle du sprite qui doit être dessiné.
     * @param height Hauteur du rectangle du sprite qui doit être dessiné.
     * @param painter Pointeur du painter de la fenêtre qui servira à dessiner.
     * @param dirMove Valeur de la direction du mouvement qui sera donnée.
     * @param animFrame Valeur de la frame d'animation qui sera donnée.
     */
    void render(qreal x, qreal y, int width, int height, QPainter *painter,int dirMove, int animFrame);

    /**
     * @brief SpriteImgMove
     * @return
     */
    bool getIsWalking() const;

    /**
     * @brief setIsWalking
     * @param value
     */
    void setIsWalking(bool value);

    /**
     * @brief getIsLookingUp
     * @return
     */
    bool getIsLookingUp() const;

    /**
     * @brief setIsLookingUp
     * @param value
     */
    void setIsLookingUp(bool value);

    /**
     * @brief getIsLookingLeft
     * @return
     */
    bool getIsLookingLeft() const;

    /**
     * @brief setIsLookingLeft
     * @param value
     */
    void setIsLookingLeft(bool value);

    /**
     * @brief getIsLookingRight
     * @return
     */
    bool getIsLookingRight() const;

    /**
     * @brief setIsLookingRight
     * @param value
     */
    void setIsLookingRight(bool value);

    /**
     * @brief getIsLookingDown
     * @return
     */
    bool getIsLookingDown() const;

    /**
     * @brief setIsLookingDown
     * @param value
     */
    void setIsLookingDown(bool value);
};

#endif // SPRITEIMGMOVE_H
