#include "personnage.h"

personnage::personnage(int x, int y,int type,int vie){
    m_x= x;
    m_y = y;
    m_type = type;
    m_vie = vie;
}

personnage::personnage(){
    m_x= -1;
    m_y = -1;
    m_type = -1;
    m_vie = -1;
}

personnage::personnage(personnage const& cp){
    m_x = cp.m_x;
    m_y = cp.m_y;
    m_type = cp.m_type;
    m_vie = cp.m_vie;
}

QVariant personnage::serial(){
    QVariant objSerial;
    objSerial.setValue(*this);
    return objSerial;
}

QString personnage::print(){

    QString a = "personnage:("+QString::number(m_x)+","+QString::number(m_y)+"):vie:"+QString::number(m_vie);
    return a;
}

QDataStream & operator >> (QDataStream & in, personnage & Valeur)
{
    in >> Valeur.m_type;
    in >> Valeur.m_x;
    in >> Valeur.m_y;
    in >> Valeur.m_vie;

    return in;
}

QDataStream & operator << (QDataStream & out, const personnage & Valeur)
{
    out << Valeur.m_type
        << Valeur.m_x
        << Valeur.m_y
        << Valeur.m_vie;

    return out;
}
