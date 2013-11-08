/*
 * @File : mainwindow.h
 * @Author: Guillaume Rasolo
 * @Description: Fenetre princial contenant la view.
 */


#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QTimer>
#include <QMainWindow>

class GameView;
class GameScene;

class GameWindow : public QMainWindow
{
private:
    GameView * gameView;
    GameScene * gameScene;
    QTimer time;
public:
    GameWindow(QWidget *parent = 0);

};

#endif // GAMEWINDOW_H
