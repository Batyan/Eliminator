/**
  * @mainpage Documentation Eliminator++
  * @section intro_sec Introduction
  *
  * Le cas d'utilisation étudié est le déplacement d'un personnage.
  *
  * @subsection tools_subsec Outils de développement:
  * - C++/Qt5.1
  *
  */

/**
  * @file main.cpp
  * @author Guillaume Rasolo
  * @date 08/11/2013
  * @version 1.0
  * @brief Le main gére le lancement du programme.
  * C'est ici que l'application lancera l'interface graphique.
  *
  */

#include <QApplication>
#include "gamewindow.h"
#include "playerlight.h"

/**
 * @brief Entrée du programme.
 * @param argc Correspond au nombre d'arguments.
 * @param argv Correspond aux arguments donnés.
 * @return Une boucle infini sur a.exec().
 *  \n a.exec() correspond est l'application graphique qui
 *  s'occupera de lancer notre programme.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaTypeStreamOperators<PlayerLight>("PlayerLight");

    Q_INIT_RESOURCE(res);
    GameWindow game;
    game.show();

    return a.exec();
}
