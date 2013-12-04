#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QPainter>
#include <QStyleOption>
#include <QPoint>
#include "movableentity.h"
#include "levelscene.h"

class Projectile : public Entity
{
public:
    Projectile();
    Projectile(qreal xpos, qreal ypos, int v, int h);

    QPainterPath shape() const;

    QRectF boundingRect()const;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);

private:
    qreal speed;

    QPoint dir;
};

#endif // PROJECTILE_H
