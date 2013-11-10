/**
  * @file gamewindow.cpp
  * @author Guillaume Rasolo
  * @date 08/11/2013
  * @version 1.0
  */

#include "gamescene.h"
#include "gameview.h"
#include "gamewindow.h"


GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent)
{
    /*On donne un titre à notre fenêtre.*/
    setWindowTitle("ELIMINATOR++");

    /*On initialise notre view et notre scène.*/
    gameScene = new GameScene();
    gameView = new GameView();

    /*On fixe la dimension de la fenêtre.*/
    setFixedSize(gameView->getSize());

    /*On configure le rectangle d'affichage de la scène, pour quelle corresponde à la vue désirée.*/
    qreal sceneWidth = (gameView->getWidth()/(2*gameView->getZoomView()))-3;
    qreal sceneHeight = (gameView->getHeight()/(2*gameView->getZoomView()))-3;
    gameScene->setSceneRect(0,0,sceneWidth,sceneHeight);

    /*On connect notre scène avec la view.*/
    gameView->setScene(gameScene);

    /*On aligne notre scène en haut à droite.*/
    gameView->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    /*On met la view au centre de notre fenetre.*/
    setCentralWidget(gameView);

    /* On connect le timer avec la scène pour que tous les 10ms advance()
     * soit appellé.
     */
    connect(&time,SIGNAL(timeout()),gameScene,SLOT(advance()));
    time.start(10);

}
