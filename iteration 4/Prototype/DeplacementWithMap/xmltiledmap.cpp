/**
  *@file xmltilemap.cpp
  *@author Michael Plong
  *@date 22/11/2013
  *@version 1.0
  */

#include <QFile>
#include <QDebug>

#include "xmltiledmap.h"

XmlTiledMap::XmlTiledMap(const QString & path)
{
    QFile file(path);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Failed to open file";
        return;
    }else{
        if(!document.setContent(&file)){
            qDebug() << "Failed to load document";
            return;
        }
        file.close();
    }

}

QString XmlTiledMap::getNameIndex(int LayerIndex)
{
    QString name;
    QDomElement root = document.firstChildElement();
    QDomNodeList items = root.elementsByTagName("tileset");

    for(int i =0; i < items.count(); i++){
        QDomNode itemnode = items.at(i);

        if(itemnode.isElement()){
            QDomElement itemele = itemnode.toElement();
            if(itemele.attribute("firstgid").toInt() == LayerIndex){
                name = itemele.attribute("name");
                break;
            }
        }
    }
    return name;

}

int XmlTiledMap::getTileId(int x, int y, QString LayerName)
{
    int id =0;
    QDomElement root = document.firstChildElement();
    QDomNodeList items = root.elementsByTagName("layer");

    for(int i =0; i < items.count(); i++){
        QDomNode itemnode = items.at(i);

        if(itemnode.isElement()){
            QDomElement itemele = itemnode.toElement();
            if(itemele.attribute("name") == LayerName){
                id = getId(x,y,itemele);
                break;
            }
        }
    }
    return id;
}


int XmlTiledMap::getNbTileWidthInMap() const
{
    QDomElement root = document.firstChildElement();
    int itemWidthNode = root.attribute("width").toInt();

    return itemWidthNode ;
}

int XmlTiledMap::getNbTileHeightInMap() const
{
    QDomElement root = document.firstChildElement();
    int itemWidthNode = root.attribute("height").toInt();

    return itemWidthNode;
}

int XmlTiledMap::getWidthTileMap() const
{
    QDomElement root = document.firstChildElement();
    int itemWidthTileNode = root.attribute("tilewidth").toInt();

    return itemWidthTileNode ;
}

int XmlTiledMap::getHeightTileMap() const
{
    QDomElement root = document.firstChildElement();
    int itemWidthTileNode = root.attribute("tileheight").toInt();

    return itemWidthTileNode;
}

int XmlTiledMap::getLayerIndexTileMap(QString name)
{
    int index = 0;
    QDomElement root = document.firstChildElement();
    QDomNodeList items = root.elementsByTagName("tileset");

    for(int i =0; i < items.count(); i++){
        QDomNode itemnode = items.at(i);

        if(itemnode.isElement()){
            QDomElement itemele = itemnode.toElement();
            if(itemele.attribute("name") == name){
                index = itemele.attribute("firstgid").toInt();
                break;
            }
        }
    }
    return index;
}

int XmlTiledMap::getId(int x, int y, QDomElement itemele)
{
    int id =0;
    QDomNodeList items = itemele.elementsByTagName("tile");

    QDomNode itemnode = items.at(x + y * 40);
    if(itemnode.isElement()){
        QDomElement item = itemnode.toElement();
        id = item.attribute("gid").toInt();
    }
    return id;
}
