/**
 * @file  gameview.cpp
 * @author Guillaume Rasolo
 * @date 08/11/2013
 * @version 2.0
 */

#include "levelscene.h"
#include "gameview.h"

GameView::GameView()
    :QGraphicsView(),viewWidth(DEFAULT_WIDTH),viewHeight(DEFAULT_HEIGHT),zoomView(DEFAULT_ZOOM)

{

    /*On fixe la dimension de la view*/
    setFixedSize(viewWidth ,viewHeight);

    /* On applique l'antialiasing pour la vue d'affichage*/
    setRenderHint(QPainter::Antialiasing);

    /*On applique le zoom à la vue d'affichage*/
    scale(zoomView,zoomView);

    /*On aligne notre scène en haut à droite.*/
    setAlignment(Qt::AlignLeft | Qt::AlignTop);

    /*On initialise notre scène.*/
    levelScene = new LevelScene();

    /*On configure le rectangle d'affichage de la scène, pour quelle corresponde à la vue désirée.*/
    qreal sceneWidth = (viewWidth/(2*zoomView))-3;
    qreal sceneHeight = (viewHeight/(2*zoomView))-3;

    levelScene->setSceneRect(0,0,sceneWidth,sceneHeight);

    /*On connect notre scène avec la view.*/
    setScene(levelScene);

    /* On connect le timer avec la scène pour que tous les 10ms advance()
     * soit appellé.
     */
    connect(&time,SIGNAL(timeout()),levelScene,SLOT(advance()));
    time.start(10);
}

QSize GameView::getSize() const
{
    return QSize(viewWidth ,viewHeight);
}


int GameView::getWidth() const
{
    return viewWidth;
}


int GameView::getHeight() const
{

    return viewHeight;
}

qreal GameView::getZoomView() const
{
    return zoomView;
}
