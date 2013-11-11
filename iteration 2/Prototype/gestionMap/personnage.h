#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "elementmap.h"

class personnage : public elementMap
{
public:
    personnage(personnage const& cp);
    personnage(int x, int y,int type,int vie);
    personnage();

    // info sur l'objet
    QString print();
    // serial de l'objet
    QVariant serial();

public:
    int m_vie;
};

Q_DECLARE_METATYPE(personnage);

/* on redéfinit les operateurs de flux pour l'object QDataStream
 * cela nous permet de sotcker et recuperer les objets serialisés dans un fihier */
QDataStream & operator << (QDataStream & out, const personnage & Valeur);
QDataStream & operator >> (QDataStream & in, personnage & Valeur);


#endif // PERSONNAGE_H
