/**
 * @file  gameview.cpp
 * @author Guillaume Rasolo
 * @date 08/11/2013
 * @version 1.0
 */

#include "gameview.h"

GameView::GameView()
    :QGraphicsView(),viewWidth(DEFAULT_WIDTH),viewHeight(DEFAULT_HEIGHT),zoomView(DEFAULT_ZOOM)

{
    /*On fixe la dimension de la view*/
    setFixedSize(viewWidth ,viewHeight);

    /* On applique l'antialiasing pour la vue d'affichage*/
    setRenderHint(QPainter::Antialiasing);

    /*On definie une image de fond d'écran pour la vue d'affichage*/
    setBackgroundBrush(QPixmap(":/res/background.png"));
    setCacheMode(QGraphicsView::CacheBackground);

    /*On applique le zoom à la vue d'affichage*/
    scale(zoomView,zoomView);
}

GameView::GameView(int width, int height)
    :QGraphicsView(),viewWidth(width),viewHeight(height)

{
    /*On fixe la dimension de la view*/
    setFixedSize(viewWidth ,viewHeight);

    /* On applique l'antialiasing pour la vue d'affichage*/
    setRenderHint(QPainter::Antialiasing);

    /*On definie une image de fond d'écran pour la vue d'affichage*/
    setBackgroundBrush(QPixmap(":/res/background.png"));
    setCacheMode(QGraphicsView::CacheBackground);

    /*On applique le zoom à la vue d'affichage*/
    scale(zoomView,zoomView);
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
