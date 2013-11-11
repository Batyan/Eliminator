#include "mur.h"

mur::mur(int x, int y,int type){
    m_x= x;
    m_y = y;
    m_type = type;
}

mur::mur(){
    m_x= -1;
    m_y = -1;
    m_type = -1;
}

mur::mur(mur const& cp){
    m_x = cp.m_x;
    m_y = cp.m_y;
    m_type = cp.m_type;
}

QVariant mur::serial(){
    QVariant objSerial;
    objSerial.setValue(*this);
    return objSerial;
}

QString mur::print(){

    QString a = "mur:("+QString::number(m_x)+","+QString::number(m_y)+")";
    return a;
}


QDataStream & operator >> (QDataStream & in, mur & Valeur)
{
    in >> Valeur.m_type;
    in >> Valeur.m_x;
    in >> Valeur.m_y;

    return in;
}

QDataStream & operator << (QDataStream & out, const mur & Valeur)
{
    out << Valeur.m_type
        << Valeur.m_x
        << Valeur.m_y;

    return out;
}
