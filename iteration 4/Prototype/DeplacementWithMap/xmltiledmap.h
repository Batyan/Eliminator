/**
  *@file xmltilemap.h
  *@author Michael Plong
  *@date 22/11/2013
  *@version 1.0
  */

#ifndef TILEDMAP_H
#define TILEDMAP_H

#include <QtXml>
#include <QDomDocument>


/**
 * @author Michael Plong
 * @brief Permet de gerer une map en xml.\n
 */
class XmlTiledMap
{
private:
    QDomDocument document;/*!< @brief Document xml. */
public:
    /**
     * @brief Constructeur XmlTiledMap
     * @detail permet de charger le fichier xml.
     */
    XmlTiledMap(const QString &path);

    /**
     * @brief getNameIndex
     * @param LayerIndex identifiant du layer.
     * @return le nom de l'index du layer.
     */
    QString getNameIndex(int LayerIndex);

    /**
     * @brief getTileId
     * @param x coordonnée x du tile.
     * @param y coordonnée y du tile.
     * @param LayerName nom du layer.
     * @return L'identifiant du layer.
     */
    int getTileId(int x, int y, QString LayerName);

    /**
     * @brief getWidthTileMap
     * @return taille d'une tile en largeur.
     */
    int getWidthTileMap()const;

    /**
     * @brief getHeightTileMap
     * @return taille d'une tile en longeur.
     */
    int getHeightTileMap()const ;

    /**
     * @brief getLayerIndexTileMap
     * @param name
     * @return le layer du nom correspondant.
     */
    int getLayerIndexTileMap(QString name);

    /**
     * @brief getNbTileHeightInMap
     * @return nombre total de tile en largeur dans la map.
     */
    int getNbTileHeightInMap() const;

    /**
     * @brief getNbTileWidthInMap
     * @return nombre total de tile en longeur dans la map.
     */
    int getNbTileWidthInMap() const;

private:
    /**
     * @brief getId
     * @param x
     * @param y
     * @param itemele
     * @return l'identifiant d'un element.
     */
    int getId(int x, int y, QDomElement itemele);
};

#endif // TILEDMAP_H
