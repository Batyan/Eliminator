#include "elementmap.h"

//contructeur
elementMap::elementMap(int x, int y,int type, QWidget *parent):QWidget(parent),m_x(x),m_y(y),m_type(type){}
elementMap::elementMap(QWidget *parent):QWidget(parent),m_x(0),m_y(0),m_type(0) {}
elementMap::elementMap(elementMap const& cp):m_x(cp.m_x),m_y(cp.m_y),m_type(cp.m_type) {}


bool elementMap::isValide(){
    return (m_type != -1);
}

QString elementMap::print(){

    QString a = "("+QString::number(m_x)+","+QString::number(m_y)+"):"+QString::number(m_type);
    return a;
}

QVariant elementMap::serial(){
    QVariant objSerial;
    objSerial.setValue(*this);
    return objSerial;
}


QDataStream & operator >> (QDataStream & in, elementMap & Valeur)
{
    in >> Valeur.m_type;
    in >> Valeur.m_x;
    in >> Valeur.m_y;

    return in;
}

QDataStream & operator << (QDataStream & out, const elementMap & Valeur)
{
    out << Valeur.m_type
        << Valeur.m_x
        << Valeur.m_y;

    return out;
}
