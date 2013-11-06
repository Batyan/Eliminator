/*
 * @File : gameview.h
 * @Author: Guillaume Rasolo
 * @Description: la classe GameView contient la scene et les parametres d'affichage standard.
 *
 */

#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QGraphicsView>

class GameView: public QGraphicsView
{
private:
    int m_width;
    int m_height;
    QString m_title;

public:
    GameView();
    GameView(int width, int height,QString title);

    QSize getSize() const;
    int getWidth() const;
    int getHeight() const;
    QString getTitle() const;
};

#endif // GAME_H
