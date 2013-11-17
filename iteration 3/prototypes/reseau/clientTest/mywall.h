#ifndef MYWALL_H
#define MYWALL_H

#include <QDataStream>
#include <QVariant>

class MyWall
{
public:
    MyWall(int x, int y, int type);
    MyWall();
    MyWall(MyWall const & mywall);

    QVariant serial();

    void print();
    qint8 x;
    qint8 y;
    qint8 type;
};

Q_DECLARE_METATYPE(MyWall);

QDataStream & operator << (QDataStream & out, const MyWall & Valeur);
QDataStream & operator >> (QDataStream & in, MyWall & Valeur);

#endif // MYWALL_H
