/*
 * @File : mainwindow.cpp
 * @Author: Guillaume Rasolo
 *
 */

#include <QLineF>
#include <QPen>
#include <QTimer>
#include <QMediaPlayer>

#include "mainwindow.h"
#include "player.h"

/**
 * @brief MainWindow::MainWindow
 * @param parent
 * @description: Initialisation de la view contenant la scene.
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    m_gameScene = new GameScene();
    m_gameView = new GameView();
    QMediaPlayer *player = new QMediaPlayer();

    QString paths = qApp->applicationDirPath();
    QString path = paths %"/res/sound/8 Bit Ain_t Nothin But a G Thang.ogg";

    QUrl url = QUrl::fromLocalFile(path);
    player->setMedia(url);

    setFixedSize(m_gameView->getSize());
    setWindowTitle(m_gameView->getTitle());

    m_gameScene->setSceneRect(0,0,m_gameView->getWidth()-3,m_gameView->getHeight()-3);


    QPen mypen = QPen(Qt::red);
    QLineF TopLine(m_gameScene->sceneRect().topLeft(),m_gameScene->sceneRect().topRight());
    QLineF LeftLine(m_gameScene->sceneRect().topLeft(),m_gameScene->sceneRect().bottomLeft());
    QLineF RightLine(m_gameScene->sceneRect().topRight(),m_gameScene->sceneRect().bottomRight());
    QLineF BottomLine(m_gameScene->sceneRect().bottomLeft(),m_gameScene->sceneRect().bottomRight());

    m_gameScene->addLine(TopLine,mypen);
    m_gameScene->addLine(LeftLine,mypen);
    m_gameScene->addLine(RightLine,mypen);
    m_gameScene->addLine(BottomLine,mypen);

    m_gameView->setScene(m_gameScene);
    m_gameView->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    setCentralWidget(m_gameView);

    player->play();
    connect(&time,SIGNAL(timeout()),m_gameScene,SLOT(advance()));
    time.start(10);

}
