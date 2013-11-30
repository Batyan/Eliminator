#include "playerlight.h"


PlayerLight::PlayerLight(int id, qreal x, qreal y, bool isNew, bool Walking, bool Right, bool Left, bool Down, bool Up)
{
    PlayerLight::id    = id;
    PlayerLight::x     = x;
    PlayerLight::y     = y;
    PlayerLight::isNew = isNew;

    PlayerLight::isWalking = Walking;
    PlayerLight::isLookingUp = Up;
    PlayerLight::isLookingLeft = Left;
    PlayerLight::isLookingRight = Right;
    PlayerLight::isLookingDown = Down;
}

PlayerLight::PlayerLight()
{
    PlayerLight::id    = -1;
    PlayerLight::x     = -1;
    PlayerLight::y     = -1;
    PlayerLight::isNew = false;

    PlayerLight::isWalking = false;
    PlayerLight::isLookingUp = false;
    PlayerLight::isLookingLeft = false;
    PlayerLight::isLookingRight = false;
    PlayerLight::isLookingDown = false;
}

PlayerLight::PlayerLight(PlayerLight const & pl)
{
    PlayerLight::id    = pl.id;
    PlayerLight::x     = pl.x;
    PlayerLight::y     = pl.y;
    PlayerLight::isNew = pl.isNew;

    PlayerLight::isWalking = pl.isWalking;
    PlayerLight::isLookingUp = pl.isLookingUp;
    PlayerLight::isLookingLeft = pl.isLookingLeft;
    PlayerLight::isLookingRight = pl.isLookingRight;
    PlayerLight::isLookingDown = pl.isLookingDown;
}

QVariant PlayerLight::serial()
{
    QVariant serial;
    serial.setValue(*this);
    return serial;
}

void PlayerLight::print()
{
    qDebug() << id << ": " << x << "." << y << "walking: " << isWalking
             << ",Up: " << isLookingRight << ",Left: "<< isLookingLeft
             << ",Right: " << isLookingDown << ",Down:" << isLookingUp;
}

QDataStream & operator >> (QDataStream & in, PlayerLight &Valeur)
{
    in >> Valeur.id;
    in >> Valeur.x;
    in >> Valeur.y;
    in >> Valeur.isNew;

    in >> Valeur.isWalking;
    in >> Valeur.isLookingUp;
    in >> Valeur.isLookingLeft;
    in >> Valeur.isLookingRight;
    in >> Valeur.isLookingDown;

    return in;
}

QDataStream & operator << (QDataStream & out, const PlayerLight & Valeur)
{
    out << Valeur.id << Valeur.x << Valeur.y << Valeur.isNew << Valeur.isWalking
           << Valeur.isLookingUp << Valeur.isLookingLeft << Valeur.isLookingRight << Valeur.isLookingDown;

    return out;
}
