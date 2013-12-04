/**
  *@file spriteimgmove.h
  *@author Guillaume Rasolo
  *@date 08/11/2013
  *@version 1.0
  *@brief Contient la description des animations.
  *@details La classe SpriteImgMove permet de gérer les animations de déplacement.
  */

#ifndef SPRITEIMGMOVE_H
#define SPRITEIMGMOVE_H

#include <QPainter>
#include <QPixmap>

/**
 * @author Guillaume Rasolo
 * @version 2.0
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

    //! @brief Constructeur SpriteImgMove.
    SpriteImgMove(QString pathSprite);

    //! @brief Permet de dessiner l'animation du sprite du personnage.
    void render(qreal x, qreal y, int width, int height, QPainter *painter,int dirMove, int animFrame);

    //! @brief getIsWalking
    bool getIsWalking() const;
    //! @brief setIsWalking
    void setIsWalking(bool value);

    //! @brief getIsLookingUp
    bool getIsLookingUp() const;
    //! @brief setIsLookingU
    void setIsLookingUp(bool value);

    //! @brief getIsLookingLeft
    bool getIsLookingLeft() const;
    //! @brief setIsLookingLeft
    void setIsLookingLeft(bool value);

    //! @brief getIsLookingRight
    bool getIsLookingRight() const;
    //! @brief setIsLookingRight
    void setIsLookingRight(bool value);

    //! @brief getIsLookingDown
    bool getIsLookingDown() const;
    //! @brief setIsLookingDown
    void setIsLookingDown(bool value);

};

#endif // SPRITEIMGMOVE_H
