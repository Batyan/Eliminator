#ifndef SCENE_H
#define SCENE_H

#include "elementmap.h"
#include "personnage.h"
#include "mur.h"

#include <QObject>
#include <QVector>

class scene : public QObject
{
    Q_OBJECT
public:
    explicit scene(QObject *parent = 0);
signals:

public slots:

public:
    QVector<elementMap*> listEleme;

};

#endif // SCENE_H
