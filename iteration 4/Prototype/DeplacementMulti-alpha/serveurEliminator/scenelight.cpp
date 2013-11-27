#include "scenelight.h"

SceneLight::SceneLight()
{
}

void SceneLight::addPlayer(PlayerLight * pl)
{
    players << pl;
}
