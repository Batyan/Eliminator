#include "sauvegarde.h"

int sauvegarde::m_nombreMurs = 0;
int sauvegarde::m_nombrePersonnages = 0;
QVector<QString> sauvegarde::m_types(2);

sauvegarde::sauvegarde(QObject *parent) :
    QObject(parent)
{
}

QVector<elementMap*> sauvegarde::restoreMap(QString name){


    m_types[0] = "mur/m";
    m_types[1] = "personnage/p";
    QVector<elementMap*> l;
    QSettings svg(name,QSettings::IniFormat);
    elementMap *e;
    int j;

    for(int i=0;i<2;i++){

        j = 1;
        do {

            switch(i){

            case 0:
                e = new mur(svg.value(m_types[i]+QString::number(j)).value<mur>());
            break;
            case 1:
                e = new personnage(svg.value(m_types[i]+QString::number(j)).value<personnage>());
            break;
            }

            if(e->isValide())
                l.append(e);
            else break;

            j++;

        } while (true);

    }

    return l;
}

void sauvegarde::storeMap(QString name,QVector<elementMap*> l){

    int len = l.count();
    elementMap *e;

    m_nombreMurs = 0;
    m_nombrePersonnages = 0;

    //creation du fichier de svg
    QSettings svg(name,QSettings::IniFormat);

    for(int i=0;i<len;i++){

        e = l.at(i);

        switch(e->m_type){

            case 0:
                m_nombreMurs++;
                svg.setValue("mur/m"+QString::number(m_nombreMurs),qVariantFromValue(e->serial()));
            break;

            case 1:
                m_nombrePersonnages++;
                svg.setValue("personnage/p"+QString::number(m_nombrePersonnages),qVariantFromValue(e->serial()));
            break;
        }
    }

}
