/**
  * @file gamewindow.cpp
  * @author Guillaume Rasolo
  * @date 08/11/2013
  * @version 2.0
  */

#include "gameview.h"
#include "gamewindow.h"
#include "mainMenu.h"

GameWindow::GameWindow(int lvl,QWidget *parent)
{

    /*On donne un titre à notre fenêtre.*/
    setWindowTitle("ELIMINATOR++");

    /*On initialise notre view.*/
    gameView = new GameView(lvl);

    /*On fixe la dimension de la fenêtre.*/
    setFixedSize(gameView->getSize());

    /*On met la view au centre de notre fenetre.*/
    QHBoxLayout *glayout = new QHBoxLayout();
    glayout->addWidget(gameView);
    setLayout(glayout);

}

GameView * GameWindow::getGameView(){
    return gameView;
}



