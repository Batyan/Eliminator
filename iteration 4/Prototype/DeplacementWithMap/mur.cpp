
#include "mur.h"

Mur::Mur()
    :SolidEntity()
{
}

Mur::Mur(qreal x, qreal y, int width, int height, int *id)
    :SolidEntity(x,y,width,height,id)
{
    ImgTilesetTerrain = QPixmap(":res/TileMap/terrain.png");
}


void Mur::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);
    int * currentId = getId();
    painter->drawPixmap(0,0,ImgTilesetTerrain,currentId[0] * getWidth(),currentId[1] * getHeight(), getWidth(), getHeight());

}

void Mur::advance(int phase)
{
    if(!phase) return;
}

QRectF Mur::boundingRect() const
{
    return QRectF (0,0,getWidth(),getHeight());
}

QPainterPath Mur::shape() const
{
    QPainterPath path;
    path.addRect(0,0,getWidth(),getHeight());
    return path;
}
