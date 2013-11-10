/*
 * @File : gameview.h
 * @Author: Guillaume Rasolo
 * @Description: la classe GameView contient la scene et les parametres d'affichage standard.
 *
 */

#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>

#define DEFAULT_WIDTH 1280
#define DEFAULT_HEIGHT 720
#define DEFAULT_ZOOM 2

class GameView: public QGraphicsView
{

private:
    int viewWidth;
    int viewHeight;
    qreal zoomView;

public:
    GameView();
    GameView(int width, int height);

    QSize getSize() const;
    int getWidth() const;
    int getHeight() const;
    qreal getZoomView() const;
};

#endif // GAMEVIEW_H
