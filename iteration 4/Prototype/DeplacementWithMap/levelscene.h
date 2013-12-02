/**
 * @file levelscene.h
 * @author Guillaume Rasolo
 * @date 08/11/2013
 * @version 1.0
 * @brief LevelScene s'occupe des objects et du chargement d'un niveau.
 * @details Elle s'occupe du comportement des objets quelles contient.
 * \n Le rafraichissement, leur position par rapport à la scène
 * et l'envoie des évènements destinés aux objets y sont gérés.
 */

#ifndef LEVEL_H
#define LEVEL_H

#include <QGraphicsScene>

#include "xmltiledmap.h"
#include "tile.h"

class NcpEnnemy;
class MovableEntity;

/**
 * @author Guillaume Rasolo
 * @version 2.0
 * @brief La classe LevelScene hérite de QGraphicsScene.\n
 * LevelScene s'occupe des objets et du chargement du niveau.
 * @details QGraphicsScene est une classe interne de Qt.
 */
class LevelScene : public QGraphicsScene
{
    Q_OBJECT
private:
    int levelId; /*!< @brief identifiant du level de la scene.*/
    Tile tile; /*!< @brief Objet Tile.*/
    MovableEntity * player; /*!< @brief Pointeur d'un objet MovableEntity.*/
    XmlTiledMap *map; /*!< @brief Objet XmlTiledMap, gestion de la map.*/
    QList<NcpEnnemy *> ennemies;  /*!< @brief Liste des ennemis.*/

    int widthTile; /*!< @brief Nombre total de Tile en largeur.*/
    int heightTile;  /*!< @brief Nombre total de Tile en longeur.*/
    int width; /*!< @brief Largeur de la map.*/
    int height;/*!< @brief Longeur de la map.*/

    const QString Dpath =":res/level/Level_"; /*!< @brief Chemin relatif des niveaux.*/
    QString path ; /*!< @brief Chemin absolu du niveau.*/

public:
    /**
     * @brief Constructeur LevelScene.
     * @details Constructeur par défaut, qui initialisera la scène.
     */
    LevelScene();

    /**
     * @brief LevelScene
     * @details Constructeur avec un niveau donnée a charger.
     * @param id correspond a un niveau.
     */
    LevelScene(int id);

protected:

    //! @brief mousePressEvent
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    //! @brief mouseReleaseEvent
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    //! @brief keyPressEvent
    void keyPressEvent(QKeyEvent *event);

public slots:
    /**
     * @brief fonction advance
     * @details la fonction advance() est appelée, lorsque l'on reçoi le signal timeout
     * du timer pour rafraîchir la scène.
     */
    void advance();

private:

    void loadWorld();/*!< @brief Permet de charger le niveau.*/

    void setLevel(int id);/*!< @brief Permet de changer de niveau.*/

    void clear();/*!< @brief Permet d'effacer  les objets contenus dans la scène.*/

};

#endif // LEVEL_H
