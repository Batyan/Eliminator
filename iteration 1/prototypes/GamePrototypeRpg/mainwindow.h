/*
 * @File : mainwindow.h
 * @Author: Guillaume Rasolo
 * @Description: Fenetre princial contenant la view.
 */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gameview.h"
#include "gamescene.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    GameView * m_gameView;
    GameScene * m_gameScene;
    QTimer time;
public:
    MainWindow(QWidget *parent = 0);

};

#endif // MAINWINDOW_H
