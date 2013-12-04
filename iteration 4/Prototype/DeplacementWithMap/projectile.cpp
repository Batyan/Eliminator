/*
 * Author: Yann Battista
 * Date: 04/12/13
 */

#include "projectile.h"

Projectile::Projectile()
    :Projectile(0,0,1,1)
{
}

Projectile::Projectile(qreal xpos, qreal ypos, int v, int h)
    :Entity(xpos, ypos, 2, 2)
{
    dir.setX(h*2);
    dir.setY(v*2);
}


void Projectile::advance(int phase)
{
    if(phase != 0)
    {
        qreal x = 0;
        qreal y = 0;
        x += dir.rx()*phase;
        y += dir.ry()*phase;
        QPoint curPos (x, y);
        QRectF rec = scene()->sceneRect();
        if(rec.contains(mapToScene(curPos)))
            setPos(mapToScene(curPos));
        else
            scene()->removeItem(this);
    }
}

void Projectile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setColor(QColor(Qt::black));
    painter->setBrush(Qt::SolidPattern);
    painter->setPen(pen);
    painter->drawEllipse(QPoint((int)this->getX(), (int)this->getY()), 3, 3);

    pen.setColor(QColor(Qt::red));
    painter->setPen(pen);
    painter->drawEllipse(QPoint((int)this->getX(), (int)this->getY()), 2, 2);

    Q_UNUSED(option); Q_UNUSED(widget);
}


QRectF Projectile::boundingRect() const
{
    return QRectF (0,0,2,2);
}

QPainterPath Projectile::shape() const
{
    QPainterPath path;
    path.addRect(0,0,2,2);
    return path;
}
