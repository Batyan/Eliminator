#include "playerlight.h"

PlayerLight::PlayerLight(int id, qreal x, qreal y, bool isNew)
{
    PlayerLight::id    = id;
    PlayerLight::x     = x;
    PlayerLight::y     = y;
    PlayerLight::isNew = isNew;
}

PlayerLight::PlayerLight()
{
    PlayerLight::id    = -1;
    PlayerLight::x     = -1;
    PlayerLight::y     = -1;
    PlayerLight::isNew = false;
}

PlayerLight::PlayerLight(PlayerLight const & pl)
{
    PlayerLight::id    = pl.id;
    PlayerLight::x     = pl.x;
    PlayerLight::y     = pl.y;
    PlayerLight::isNew = pl.isNew;
}

QVariant PlayerLight::serial()
{
    QVariant serial;
    serial.setValue(*this);
    return serial;
}

void PlayerLight::print()
{
    qDebug() << id << ": " << x << "." << y;
}

QDataStream & operator >> (QDataStream & in, PlayerLight &Valeur)
{
    in >> Valeur.id;
    in >> Valeur.x;
    in >> Valeur.y;
    in >> Valeur.isNew;

    return in;
}

QDataStream & operator << (QDataStream & out, const PlayerLight & Valeur)
{
    out << Valeur.id << Valeur.x << Valeur.y << Valeur.isNew;

    return out;
}
