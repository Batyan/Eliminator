#ifndef ENTITY_H
#define ENTITY_H


#include <QGraphicsItem>

class Entity : public QGraphicsItem
{
private:
    int eWidth;
    int eHeight;

public:
    Entity(qreal x, qreal y, int width, int height);

    int getWidth() const;
    int getHeight() const;

    qreal getX() const;
    qreal getY() const;

    virtual ~Entity();

};

#endif // ENTITY_H
