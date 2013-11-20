/**
  * @file gamewindow.h
  * @author Guillaume Rasolo
  * @date 08/11/2013
  * @version 1.0
  * @brief GameWindow s'occupe de l'affichage.
  * @details Elle a pour but de connecter une scène avec une view, pour
  * afficher les éléments dans la fenêtre.
  *
  */
#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QTimer>
#include <QMainWindow>

class GameView;
class GameScene;

/**
 * @author Guilaume Rasolo
 * @version 1.0
 * @brief La classe GameWindow hérite de QMainWindow.\n
 * GameWindow s'occupe de l'affichage.
 * @details QMainWindow est une classe interne de Qt.
 */
class GameWindow : public QMainWindow
{
private:
    GameView * gameView; /*!< @brief La view qui contiendra la scène. */
    GameScene * gameScene; /*!< @brief La scène qui contiendra les objects. */
    QTimer time; /*!< @brief Le timer qui s'occupera du rafraîchissement de la scène.*/
public:
    /**
     * @brief Constructeur GameWindow.
     * @param parent Pointeur vers un QWidget parent, initialiser à 0.
     * @details Le constructeur s'occupera de mettre en liaison la scène avec la
     * view. Il gére aussi la dimension de la fenêtre, le titre et le timer.
     */
    GameWindow(QWidget *parent = 0);

};

#endif // GAMEWINDOW_H
