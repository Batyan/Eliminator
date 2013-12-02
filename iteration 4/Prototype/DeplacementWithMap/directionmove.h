/**
  *@file directionmove.h
  *@author Guillaume Rasolo
  *@date 08/11/2013
  *@version 1.0
  *@brief Contient l'enum DirectionMove
  */

#ifndef DIRECTIONPOS_H
#define DIRECTIONPOS_H

/**
 * @brief The DirectionMove enum
 * @details DirectionMove est une série de constantes prédéfinie pour définir la
 * la direction de déplacement.
 */
enum DirectionMove{
    DIR_DOWN_MOVING, /*!< @brief Déplacement vers le bas.*/
    DIR_LEFT_MOVING, /*!< @brief Déplacement vers la gauche.*/
    DIR_UP_MOVING, /*!< @brief Déplacement vers le haut.*/
    DIR_RIGHT_MOVING /*!< @brief Déplacement vers la droite.*/
};

#endif // DIRECTIONPOS_H
