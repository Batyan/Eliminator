#ifndef PLAYERLIGHT_H
#define PLAYERLIGHT_H

#include <QtGlobal>
#include <QTcpSocket>
#include <QDataStream>

class PlayerLight
{
public:
    PlayerLight(int id, qreal x, qreal y, bool isNew);
    PlayerLight();
    PlayerLight(PlayerLight const & pl);

    QVariant serial();
    void print();

    int id;
    qreal x;
    qreal y;
    bool isNew;

};

Q_DECLARE_METATYPE(PlayerLight);

QDataStream & operator << (QDataStream & out, const PlayerLight & Valeur);
QDataStream & operator >> (QDataStream & in, PlayerLight & Valeur);

#endif // PLAYERLIGHT_H
