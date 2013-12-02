/**
  *@file solidentity.h
  *@author Guillaume Rasolo
  *@date 25/11/2013
  *@version 1.0
  *@brief Contient la définition d'une SolidEntity.
  */

#ifndef SOLIDENTITY_H
#define SOLIDENTITY_H

#include "entity.h"

/**
 * @author Guillaume Rasolo
 * @version 1.0
 * @brief La classe SolidEntity hérite de Entity.\n
 */
class SolidEntity: public Entity
{
private:
    int *id; /*!< @brief Pointeur de l'idenfiant de l'entity. */
public:

    //! @brief Constructeur par defaut de SolidEntity.
    SolidEntity();

    //! @brief Constructeur SolidEntity.
    SolidEntity(qreal x, qreal y, int width, int height, int *id);

    //! @brief l'identifiant de l'entity.
    int *getId() const;

};

#endif // SOLIDENTITY_H
