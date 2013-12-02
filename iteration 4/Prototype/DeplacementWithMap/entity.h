/**
  *@file entity.h
  *@author Guillaume Rasolo
  *@date 08/11/2013
  *@version 1.0
  *@brief Contient la définition d'une Entity.
  */

#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsItem>

/**
 * @author Guillaume Rasolo
 * @version 1.0
 * @brief La classe Entity hérite de QGraphicsItem.\n
 * Contient la définition d'une Entity.
 * @details QGraphicsItem est une classe interne de Qt.
 */
class Entity : public QGraphicsItem
{
private:
    int eWidth; /*!< @brief Largeur de l'entity. */
    int eHeight; /*!< @brief Hauteur de l'entity. */

public:
    /**
     * @brief Constructeur Entity.
     * @param x Coordonnée x qui sera donner à l'entity.
     * @param y Coordonnée y qui sera donner à l'entity.
     * @param width Largeur qui sera donner à l'entity.
     * @param height Hauteur qui sera donner à l'entity.
     * @details On définie une entity, avec une position et une taille.
     */
    Entity(qreal x, qreal y, int width, int height);

    /**
     * @brief isInCollision
     * @return vrai si l'entity est en collision avec un autre objet.
     */
    bool isCollision();

    //! @brief getWidth
    int getWidth() const;

    //! @brief getHeight
    int getHeight() const;

    //! @brief getX
    qreal getX() const;

    //! @brief getY
    qreal getY() const;

};

#endif // ENTITY_H
