#include "changemap.h"


ChangeMap::ChangeMap(int id)
{
    ChangeMap::id    = id;
}

ChangeMap::ChangeMap()
{
    ChangeMap::id    = 1;
}

ChangeMap::ChangeMap(ChangeMap const & cm)
{
    ChangeMap::id = cm.id;
}

QVariant ChangeMap::serial()
{
    QVariant serial;
    serial.setValue(*this);
    return serial;
}

void ChangeMap::print()
{
    qDebug() << "id map: " << id;
}

QDataStream & operator >> (QDataStream & in, ChangeMap &Valeur)
{
    in >> Valeur.id;

    return in;
}

QDataStream & operator << (QDataStream & out, const ChangeMap & Valeur)
{
    out << Valeur.id;

    return out;
}
