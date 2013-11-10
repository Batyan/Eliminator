/*
 * @File : gameview.cpp
 * @Author: Guillaume Rasolo
 *
 */

#include "gameview.h"

/**
 * @brief GameView::GameView
 */
GameView::GameView()
    :QGraphicsView(),viewWidth(DEFAULT_WIDTH),viewHeight(DEFAULT_HEIGHT),zoomView(DEFAULT_ZOOM)

{

    setFixedSize(viewWidth ,viewHeight);
    setRenderHint(QPainter::Antialiasing);

    setBackgroundBrush(QPixmap(":/res/background.png"));
    setCacheMode(QGraphicsView::CacheBackground);
    scale(zoomView,zoomView);
}

/**
 * @brief GameView::GameView
 * @param width
 * @param height
 * @param title
 */
GameView::GameView(int width, int height)
    :QGraphicsView(),viewWidth(width),viewHeight(height)

{
    setFixedSize(viewWidth ,viewHeight);
    setRenderHint(QPainter::Antialiasing);

    setBackgroundBrush(QPixmap(":/res/background.png"));
    setCacheMode(QGraphicsView::CacheBackground);
    scale(zoomView,zoomView);
}

/**
 * @brief GameView::getSize
 * @return QSize
 */
QSize GameView::getSize() const
{
    return QSize(viewWidth ,viewHeight);
}

/**
 * @brief GameView::getWidth
 * @return int
 */
int GameView::getWidth() const
{
    return viewWidth;
}

/**
 * @brief GameView::getHeight
 * @return int
 */
int GameView::getHeight() const
{
    return viewHeight;
}

qreal GameView::getZoomView() const
{
    return zoomView;
}
