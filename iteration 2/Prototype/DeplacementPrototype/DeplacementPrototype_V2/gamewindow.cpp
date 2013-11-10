/*
 * @File : mainwindow.cpp
 * @Author: Guillaume Rasolo
 *
 */

#include <QLineF>
#include <QPen>

#include "gamescene.h"
#include "gameview.h"
#include "gamewindow.h"

/**
 * @brief MainWindow::MainWindow
 * @param parent
 * @description: Initialisation de la view contenant la scene.
 */
GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("ELIMINATOR++");

    gameScene = new GameScene();
    gameView = new GameView();

    setFixedSize(gameView->getSize());

    qreal sceneWidth = (gameView->getWidth()/(2*gameView->getZoomView()))-3;
    qreal sceneHeight = (gameView->getHeight()/(2*gameView->getZoomView()))-3;
    gameScene->setSceneRect(0,0,sceneWidth,sceneHeight);

    QPen mypen = QPen(Qt::red);
    QLineF TopLine(gameScene->sceneRect().topLeft(),gameScene->sceneRect().topRight());
    QLineF LeftLine(gameScene->sceneRect().topLeft(),gameScene->sceneRect().bottomLeft());
    QLineF RightLine(gameScene->sceneRect().topRight(),gameScene->sceneRect().bottomRight());
    QLineF BottomLine(gameScene->sceneRect().bottomLeft(),gameScene->sceneRect().bottomRight());

    gameScene->addLine(TopLine,mypen);
    gameScene->addLine(LeftLine,mypen);
    gameScene->addLine(RightLine,mypen);
    gameScene->addLine(BottomLine,mypen);


    gameView->setScene(gameScene);
    gameView->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    setCentralWidget(gameView);

    connect(&time,SIGNAL(timeout()),gameScene,SLOT(advance()));
    time.start(10);

}
