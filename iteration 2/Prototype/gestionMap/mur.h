#ifndef MUR_H
#define MUR_H

#include "elementmap.h"
#include <QWidget>
#include <QVariant>
#include <QString>

class mur : public elementMap
{
public:
    mur(mur const& cp);
    mur(int x, int y,int type);
    mur();
    // info sur l'objet
    QString print();
    // serial de l'objet
    QVariant serial();


};

Q_DECLARE_METATYPE(mur);

/* on redéfinit les operateurs de flux pour l'object QDataStream
 * cela nous permet de sotcker et recuperer les objets serialisés dans un fihier */
QDataStream & operator << (QDataStream & out, const mur & Valeur);
QDataStream & operator >> (QDataStream & in, mur & Valeur);

#endif // MUR_H
