#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

#include "elementmap.h"
#include "personnage.h"
#include "mur.h"

#include <QObject>
#include <QVector>
#include <QSettings>
#include <QDebug>s

class sauvegarde : public QObject
{
    Q_OBJECT
public:
    explicit sauvegarde(QObject *parent = 0);

    /* On récupère les données de la map (objets serializés) et on renvoi la liste des objets réinstanciés  */
    static QVector<elementMap*> restoreMap(QString name);

    /* On enregistre les données de la map (objets serializés) dans un .ini */
    static void storeMap(QString name,QVector<elementMap*> l);

signals:

public slots:
public:
    static int m_nombreMurs;
    static int m_nombrePersonnages;
    static QVector<QString> m_types;

};

#endif // SAUVEGARDE_H
