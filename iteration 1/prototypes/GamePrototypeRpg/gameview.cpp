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
    :QGraphicsView(),m_width(1280),m_height(720),m_title("Game")

{

    setFixedSize(m_width ,m_height);
    setRenderHint(QPainter::Antialiasing);

    setBackgroundBrush(QPixmap(":/res/background.png"));
    setCacheMode(QGraphicsView::CacheBackground);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
}

/**
 * @brief GameView::GameView
 * @param width
 * @param height
 * @param title
 */
GameView::GameView(int width, int height, QString title)
    :QGraphicsView(),m_width(width),m_height(height),m_title(title)

{
    setFixedSize(m_width ,m_height);
    setRenderHint(QPainter::Antialiasing);

    setBackgroundBrush(QPixmap(":/res/background.png"));
    setCacheMode(QGraphicsView::CacheBackground);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
}

/**
 * @brief GameView::getSize
 * @return QSize
 */
QSize GameView::getSize() const
{
    return QSize(m_width ,m_height);
}

/**
 * @brief GameView::getWidth
 * @return int
 */
int GameView::getWidth() const
{
    return m_width;
}

/**
 * @brief GameView::getHeight
 * @return int
 */
int GameView::getHeight() const
{
    return m_height;
}

/**
 * @brief GameView::getTitle
 * @return QString
 */
QString GameView::getTitle() const
{
    return m_title;
}
