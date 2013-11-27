#ifndef SCENELIGHT_H
#define SCENELIGHT_H

#include <QList>

#include "entitylight.h"
#include "playerlight.h"

class SceneLight
{
public:
    SceneLight();
    void addPlayer(PlayerLight * pl);
private:
    QList<EntityLight *> players;
};

#endif // SCENELIGHT_H
