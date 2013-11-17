#include "mywall.h"
#include <QDebug>

MyWall::MyWall(int x, int y, int type)
{
    this->x = x;
    this->y = y;
    this->type = type;
}

MyWall::MyWall()
{
    this->x = -1;
    this->y = -1;
    this->type = -1;
}

MyWall::MyWall(MyWall const &mywall)
{
    this->x = mywall.x;
    this->y = mywall.y;
    this->type = mywall.type;
}

QVariant MyWall::serial()
{
    QVariant serial;
    serial.setValue(*this);
    return serial;
}

void MyWall::print()
{
    qDebug() << this->x << this->y << this->type;
}

QDataStream & operator >> (QDataStream & in, MyWall & Valeur)
{
    in >> Valeur.type;
    in >> Valeur.x;
    in >> Valeur.y;

    return in;
}

QDataStream & operator << (QDataStream & out, const MyWall & Valeur)
{
    out << Valeur.type;
    out << Valeur.x;
    out << Valeur.y;

    return out;
}
