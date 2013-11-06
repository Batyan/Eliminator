/*
 * @File : ncp.cpp
 * @Author: Guillaume Rasolo
 *
 */


#include <QPainter>
#include <QGraphicsScene>
#include <QPointF>
#include <QDebug>

#include "ncp.h"

/**
 * @brief Ncp::Ncp
 */
Ncp::Ncp():QGraphicsRectItem(),
    m_isWalking(false), m_scaleNcp(2)
{
    m_speedWalking = 2;

    m_sprite = QPixmap(":res/Ncp/default.png");

    m_animDelta =0;
    m_animTime = 5;
    m_dir =0;
    m_animFrame=0;
    m_pWidth = 32;
    m_pHeight = 32;

    for(int i =0; i < 3;i++){
        if(i ==0){
            s_pImgDown[i][0] = i;
            s_pImgDown[i][1] = 0;
            s_pImgLeft[i][0] = i;
            s_pImgLeft[i][1] = 1;
            s_pImgRight[i][0] = i;
            s_pImgRight[i][1] = 2;
            s_pImgUp[i][0] = i;
            s_pImgUp[i][1] = 3;
        }else if(i == 1){
            s_pImgDown[i][0] = i;
            s_pImgDown[i][1] = 0;
            s_pImgLeft[i][0] = i;
            s_pImgLeft[i][1] = 1;
            s_pImgRight[i][0] = i;
            s_pImgRight[i][1] = 2;
            s_pImgUp[i][0] = i;
            s_pImgUp[i][1] = 3;
        }else if(i== 2){
            s_pImgDown[i][0] = i;
            s_pImgDown[i][1] = 0;
            s_pImgLeft[i][0] = i;
            s_pImgLeft[i][1] = 1;
            s_pImgRight[i][0] = i;
            s_pImgRight[i][1] = 2;
            s_pImgUp[i][0] = i;
            s_pImgUp[i][1] = 3;
        }

    }

    m_isUp = m_isLeft = m_isRight = m_isDown = m_isRun = false;

    setRect(0,0,m_pWidth,m_pHeight);
    setPos(mapToParent(qrand()%250,qrand()%150));
    setActive(true);
    setFlag(QGraphicsItem::ItemIsMovable);
}

/**
 * @brief Ncp::Ncp
 * @param specialNcp
 */
Ncp::Ncp(QString specialNcp)
    :QGraphicsRectItem(),m_isWalking(false), m_scaleNcp(2)
{
    m_speedWalking = 2;

    m_sprite = QPixmap(QString(":res/Ncp/%1.png").arg(specialNcp));

    m_animDelta =0;
    m_animTime = 20;
    m_dir =0;
    m_animFrame=0;
    m_pWidth = 32;
    m_pHeight = 32;

    for(int i =0; i < 3;i++){
        if(i ==0){
            s_pImgDown[i][0] = i;
            s_pImgDown[i][1] = 0;
            s_pImgLeft[i][0] = i;
            s_pImgLeft[i][1] = 1;
            s_pImgRight[i][0] = i;
            s_pImgRight[i][1] = 2;
            s_pImgUp[i][0] = i;
            s_pImgUp[i][1] = 3;
        }else if(i == 1){
            s_pImgDown[i][0] = i;
            s_pImgDown[i][1] = 0;
            s_pImgLeft[i][0] = i;
            s_pImgLeft[i][1] = 1;
            s_pImgRight[i][0] = i;
            s_pImgRight[i][1] = 2;
            s_pImgUp[i][0] = i;
            s_pImgUp[i][1] = 3;
        }else if(i== 2){
            s_pImgDown[i][0] = i;
            s_pImgDown[i][1] = 0;
            s_pImgLeft[i][0] = i;
            s_pImgLeft[i][1] = 1;
            s_pImgRight[i][0] = i;
            s_pImgRight[i][1] = 2;
            s_pImgUp[i][0] = i;
            s_pImgUp[i][1] = 3;
        }

    }

    m_isUp = m_isLeft = m_isRight = m_isDown = m_isRun = false;

    setRect(0,0,m_pWidth,m_pHeight);
    setPos(mapToParent(qrand()%250,qrand()%150));
    setActive(true);
    setFlag(QGraphicsItem::ItemIsMovable);
}

/**
 * @brief Ncp::paint
 * @param painter
 * @param option
 * @param widget
 */
void Ncp::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
    painter->scale(m_scaleNcp,m_scaleNcp);

    if(m_dir == 0){
        if(m_isWalking){
            painter->drawPixmap(x(),y(),m_sprite,s_pImgDown[m_animFrame][0] * m_pWidth,s_pImgDown[m_animFrame][1] * m_pHeight,m_pWidth, m_pHeight);
        }else{
            painter->drawPixmap(x(),y(),m_sprite,s_pImgDown[0][0] * m_pWidth,s_pImgDown[0][1] * m_pHeight,m_pWidth, m_pHeight);
        }
    }

    if(m_dir == 1){
        if(m_isWalking){
            painter->drawPixmap(x(),y(),m_sprite,s_pImgLeft[m_animFrame][0] * m_pWidth,s_pImgLeft[m_animFrame][1] * m_pHeight,m_pWidth, m_pHeight );
        }else{
            painter->drawPixmap(x(),y(),m_sprite,s_pImgLeft[0][0] * m_pWidth,s_pImgLeft[0][1] * m_pHeight,m_pWidth,m_pHeight );
        }
    }

    if(m_dir == 2){
        if(m_isWalking){
            painter->drawPixmap(x(),y(),m_sprite,s_pImgUp[m_animFrame][0] * m_pWidth,s_pImgUp[m_animFrame][1] * m_pHeight, m_pWidth, m_pHeight );
        }else{
            painter->drawPixmap(x(),y(),m_sprite,s_pImgUp[0][0] * m_pWidth,s_pImgUp[0][1] * m_pHeight,m_pWidth,m_pHeight);
        }
    }

    if(m_dir == 3){
        if(m_isWalking){
            painter->drawPixmap(x(),y(),m_sprite,s_pImgRight[m_animFrame][0] * m_pWidth,s_pImgRight[m_animFrame][1] * m_pHeight,m_pWidth, m_pHeight );
        }else{
            painter->drawPixmap(x(),y(),m_sprite,s_pImgRight[0][0] * m_pWidth,s_pImgRight[0][1] * m_pHeight,m_pWidth,m_pHeight );
        }
    }
    painter->resetTransform();
}

/**
 * @brief Ncp::advance
 * @param phase
 */
void Ncp::advance(int phase)
{
    if(!phase) return;

    int xa = 0, ya =0;

    m_animDelta++;
    m_animTime +=m_speedWalking;

    if(m_animDelta >= m_animTime){
        m_animFrame++;
        m_animDelta =0;

        if(m_animFrame > 2){
            m_animFrame =0;
        }
        simpleAI(xa,ya);
    }

    m_animTime = 5;
}

/**
 * @brief Ncp::boundingRect
 * @return
 */
QRectF Ncp::boundingRect() const
{
    return QRect(0,0,m_pWidth,m_pHeight);
}


/**
 * @brief Ncp::move
 * @param xa
 * @param ya
 */
void Ncp::move(int xa, int ya)
{
    if(xa != 0 && ya != 0){
        move(xa,0);
        move(0,ya);
        return;
    }

    if(ya > 0){
        m_dir = 0;
    }

    if(ya < 0){
        m_dir = 2;
    }

    if(xa > 0){
        m_dir = 3;
    }

    if(xa < 0){
        m_dir =1;
    }

    /** Dans le futur: c'est ici qu'il
     *faut appeller le gestionnaire des collision**/
    //if(scene()->collidingItems(this).isEmpty()){
       setPos(mapToParent(xa,ya));

}

/**
 * @brief Ncp::simpleAI
 * @param xa
 * @param ya
 */
void Ncp::simpleAI(int xa, int ya)
{
    int n = qrand()%8;

    if(n==0){
        ya -= m_speedWalking;
    }

    if(n==1){
        ya += m_speedWalking;
    }

    if(n==2){
        xa -= m_speedWalking;
    }

    if(n==3){
        xa += m_speedWalking;
    }

    if(xa != 0 || ya != 0){
        m_isWalking = true;
        move(xa,ya);
    }else{
        m_isWalking = false;
    }

}
