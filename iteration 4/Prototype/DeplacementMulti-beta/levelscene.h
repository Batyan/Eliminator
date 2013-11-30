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

#include <QString>
#include <QGraphicsScene>
#include <QKeyEvent>

#include "xmltiledmap.h"
#include "tile.h"
#include "player.h"
#include "playerlight.h"
class MovableEntity;


/**
 * @author Guillaume Rasolo
 * @version 1.0
 * @brief La classe LevelScene hérite de QGraphicsScene.\n
 * LevelScene s'occupe des objets et du chargement du niveau.
 * @details QGraphicsScene est une classe interne de Qt.
 */
class LevelScene : public QGraphicsScene
{
    Q_OBJECT
private:
    Tile tile; /*!< @brief Objet Tile.*/
    MovableEntity * player; /*!< @brief Pointeur d'un objet MovableEntity.*/
    QList<MovableEntity *> otherPlayers;

    XmlTiledMap *map; /*!< @brief Objet XmlTiledMap, gestion de la map.*/

    int widthTile; /*!< @brief Nombre total de Tile en largeur.*/
    int heightTile;  /*!< @brief Nombre total de Tile en longeur.*/
    int width; /*!< @brief Largeur de la map.*/
    int height;/*!< @brief Longeur de la map.*/

    const QString Dpath =":res/level/Level_"; /*!< @brief Chemin relatif de la map.*/
    QString path ; /*!< @brief Chemin absolu de la map.*/


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

    MovableEntity * getLocalPlayer();
    bool addPlayer(PlayerLight pl, bool isLocal);
    void removePlayer(int id);
    void movePlayer(int id,qreal x, qreal y, bool Walking, bool Right, bool Left, bool Down, bool Up);
protected:
    /**
     * @brief mousePressEvent
     * @param event Événement souris.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    /**
     * @brief mouseReleaseEvent
     * @param event Événement souris.
     */
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    void keyPressEvent(QKeyEvent *event);

    void keyReleaseEvent(QKeyEvent *event);
public slots:
    /**
     * @brief fonction advance
     * @details la fonction advance() est appelée, lorsque l'on reçoi le signal timeout
     * du timer pour rafraîchir la scène.
     */
    void advance();

private:
    /**
     * @brief loadWorld
     * @details Permet de charger un niveau.
     */
    void loadWorld();
signals:
    void sendPos(qreal,qreal, bool,bool,bool,bool, bool);

};

#endif // LEVEL_H
