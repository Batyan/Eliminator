#ifndef PLAYERLIGHT_H
#define PLAYERLIGHT_H

#include <QtGlobal>
#include <QTcpSocket>
#include <QDataStream>

class ChangeMap
{
public:
    ChangeMap(int id);
    ChangeMap();
    ChangeMap(ChangeMap const & cm);

    QVariant serial();
    void print();

    int id;
};

Q_DECLARE_METATYPE(ChangeMap)

QDataStream & operator << (QDataStream & out, const ChangeMap & Valeur);
QDataStream & operator >> (QDataStream & in, ChangeMap & Valeur);

#endif // PLAYERLIGHT_H
