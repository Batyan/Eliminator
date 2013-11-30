#ifndef PLAYERLIGHT_H
#define PLAYERLIGHT_H

#include <QtGlobal>
#include <QTcpSocket>
#include <QDataStream>

class PlayerLight
{
public:
    PlayerLight(int id, qreal x, qreal y,
                bool isNew = false,bool Walking= false,
                bool Right= false, bool Left= false, bool Down= false, bool Up= false);
    PlayerLight();
    PlayerLight(PlayerLight const & pl);

    QVariant serial();
    void print();

    int id;
    qreal x;
    qreal y;
    bool isNew;

    bool isWalking;
    bool isLookingUp;
    bool isLookingLeft;
    bool isLookingRight;
    bool isLookingDown;

};

Q_DECLARE_METATYPE(PlayerLight)

QDataStream & operator << (QDataStream & out, const PlayerLight & Valeur);
QDataStream & operator >> (QDataStream & in, PlayerLight & Valeur);

#endif // PLAYERLIGHT_H
