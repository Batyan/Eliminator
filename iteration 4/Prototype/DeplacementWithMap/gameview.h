/**
  * @file gameview.h
  * @author Guillaume Rasolo
  * @date 08/11/2013
  * @version 2.0
  * @brief GameView s'occupe de la vue d'affichage d'une scène.
  * @details Elle a pour but de positionner/configurer l'affichage d'une scène.
  */
#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QTimer>
#include <QGraphicsView>

//! @def DEFAULT_WIDTH
//! @brief Correspond à la largeur par défaut que prendra la fenêtre.
#define DEFAULT_WIDTH 1280

//! @def DEFAULT_HEIGHT
//! @brief Correspond à la hauteur par défaut que prendra la fenêtre.
#define DEFAULT_HEIGHT 736

//! @def DEFAULT_ZOOM
//! @brief Correspond au zoom par défaut qui sera appliquer à la vue d'affichage.
#define DEFAULT_ZOOM 1

class LevelScene;

/**
 * @author Guilaume Rasolo
 * @version 2.0
 * @brief La classe GameView hérite de QGraphicsView.\n
 * GameView s'occupe de la vue d'affichage d'une scène.
 * @details QGraphicsView est une classe interne de Qt.
 */
class GameView: public QGraphicsView
{

private:
    int viewWidth; /*!< @brief Largeur de la view. */
    int viewHeight; /*!< @brief Hauteur de la view. */
    qreal zoomView; /*!< @brief Zoom de la view.*/

    LevelScene * levelScene; /*!< @brief La scène qui contiendra les objects. */
    QTimer time; /*!< @brief Le timer qui s'occupera du rafraîchissement de la scène.*/

public:
    /**
     * @brief Constructeur GameView par défaut.
     * @details Constructeur par défaut, qui initialisera la view avec les paramètres
     * par défaut.
     */
    GameView();

    //! @brief getSize
    QSize getSize() const;

    //! @brief getZoomView
    qreal getZoomView() const;

    //! @brief getWidth
    int getWidth() const;

    //! @brief getWidth
    int getHeight() const;


};

#endif // GAMEVIEW_H
