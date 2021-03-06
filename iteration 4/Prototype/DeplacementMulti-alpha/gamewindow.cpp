/**
  * @file gamewindow.cpp
  * @author Guillaume Rasolo
  * @date 08/11/2013
  * @version 2.0
  */

#include "gameview.h"
#include "gamewindow.h"


GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent)
{
    /*On donne un titre à notre fenêtre.*/
    setWindowTitle("ELIMINATOR++");

    /*On initialise notre view.*/
    gameView = new GameView();

    /*On fixe la dimension de la fenêtre.*/
    setFixedSize(gameView->getSize());

    /*On met la view au centre de notre fenetre.*/
    setCentralWidget(gameView);

}
