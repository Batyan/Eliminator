#ifndef OBJ_H
#define OBJ_H

#include <QGraphicsItem>

class obj : public QGraphicsItem
{
public:
    obj();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

protected:
    void advance(int step);

private:
    qreal angle;
    qreal speed;
};

#endif // OBJ_H
