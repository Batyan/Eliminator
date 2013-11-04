#include "obj.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

#include "math.h"

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}

obj::obj()
    : angle(0), speed(0)
{
    setRotation(qrand() % (360 * 16));
}

QRectF obj::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}

void obj::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawImage(0, 0, QImage("../protoDeplacementImage/img/BatSmall.png"), 0, 0, 20, 20);
}


void obj::advance(int step)
{
    if (!step)
        return;
    // Don't move too far away
    QLineF lineToCenter(QPointF(0, 0), mapFromScene(0, 0));
    if (lineToCenter.length() > 150) {
        qreal angleToCenter = ::acos(lineToCenter.dx() / lineToCenter.length());
        if (lineToCenter.dy() < 0)
            angleToCenter = TwoPi - angleToCenter;
        angleToCenter = normalizeAngle((Pi - angleToCenter) + Pi / 2);

        if (angleToCenter < Pi && angleToCenter > Pi / 4) {
            // Rotate left
            angle += (angle < -Pi / 2) ? 0.25 : -0.25;
        } else if (angleToCenter >= Pi && angleToCenter < (Pi + Pi / 2 + Pi / 4)) {
            // Rotate right
            angle += (angle < Pi / 2) ? 0.25 : -0.25;
        }
    } else if (::sin(angle) < 0) {
        angle += 0.25;
    } else if (::sin(angle) > 0) {
        angle -= 0.25;
    }

    if (qrand() % 1)
        angle += (qrand() % 100) / 500.0;
    else
        angle -= (qrand() % 100) / 500.0;

    speed += (-50 + qrand() % 100) / 100.0;

    qreal dx = ::sin(angle) * 10;

    setRotation(rotation() + dx);
    setPos(mapToParent(0, -(3 + sin(speed) * 3)));
}

QPainterPath obj::shape() const
{
    QPainterPath path;
    path.addRect(-10, -10, 20, 20);
    return path;
}
