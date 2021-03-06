/**
 * @file mur.h
 * @author Guillaume Rasolo
 * @date 25/11/2013
 * @version 1.0
 * @brief Contient la définition d'un mur.
 */

#ifndef SOLID_H
#define SOLID_H

#include <QPainter>
#include <QPixmap>

#include "solidentity.h"

/**
 * @author Guillaume Rasolo
 * @version 1.0
 * @brief La classe Mur hérite de SolidEntity.\n
 * Contient la définition d'un mur.
 */
class Mur : public SolidEntity
{
private:
    QPixmap ImgTilesetTerrain;/*!< TileSet des mur.*/
public:

    //! @brief Constructeur par defaut de Mur.
    Mur();

    //! @brief Constructeur  de Mur.
    Mur(qreal x, qreal y, int width, int height, int *id = 0);

    //! @brief Permet l'affichage d'un mur.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //! @brief Permet le rafraîchissement de l'objet.
    void advance(int phase);

    //! @brief boundingRect
    QRectF boundingRect()const;

    //! @brief shape
    QPainterPath shape() const;
};

#endif // SOLID_H
