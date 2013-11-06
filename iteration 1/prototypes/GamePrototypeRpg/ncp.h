/*
 * @File : ncp.h
 * @Author: Guillaume Rasolo
 * @Description: Contient la description d'un Ncp avec une AI basic
 *
 */


#ifndef NCP_H
#define NCP_H

#include <QtCore>
#include <QPixmap>
#include <QGraphicsRectItem>

class Ncp:public QGraphicsRectItem
{
private:
    QPixmap m_sprite;
    bool m_isWalking;
    bool m_isUp, m_isLeft, m_isRight, m_isDown,m_isRun;
    int m_speedWalking;

    int m_animDelta;
    int m_animTime;
    int m_animFrame;
    int m_dir;
    int m_scaleNcp;

    int m_pWidth;
    int m_pHeight;

    int s_pImgDown[3][2];
    int s_pImgLeft[3][2];
    int s_pImgRight[3][2];
    int s_pImgUp[3][2];
public:
    Ncp();
    Ncp(QString specialNcp);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    QRectF boundingRect() const;

private:
    void move(int xa, int ya);
    void simpleAI(int xa,int ya);
};

#endif // NCP_H
