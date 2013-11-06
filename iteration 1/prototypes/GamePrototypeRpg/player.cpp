/*
 * @File : player.cpp
 * @Author: Guillaume Rasolo
 *
 */

#include <QPainter>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QPointF>
#include <QDebug>

#include "player.h"

/**
 * @brief Player::Player
 */
PlayerSound::PlayerSound()
    :QGraphicsRectItem(),m_isWalking(false), m_scalePlayer(2)
{
    m_speedWalking = 2;

    m_sprite = QPixmap(":res/characters.png");

    m_animDelta =0;
    m_animTime = 10;
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
    setPos(mapToParent(150,150));
    setActive(true);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFocus();
}

/**
 * @brief Player::paint
 * @param painter
 * @param option
 * @param widget
 */
void PlayerSound::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
    painter->scale(m_scalePlayer,m_scalePlayer);

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

    QRectF rec = boundingRect();
    QBrush brush (Qt::green);
    if(!scene()->collidingItems(this).isEmpty()){
        brush.setColor(Qt::red);
    }

    painter->fillRect(rec,brush);
    painter->drawRect(rec);

}

/**
 * @brief Player::advance
 * @param phase
 */
void PlayerSound::advance(int phase)
{
    // qDebug() << "focus PLAYER? " << this->hasFocus();
    if(!phase) return;

    int xa = 0, ya =0;

    if(m_isRun){
        m_speedWalking = 10;
    }else{
        m_speedWalking = 2;
    }

    m_animDelta++;
    m_animTime +=m_speedWalking;

    if(m_animDelta >= m_animTime){
        m_animFrame++;
        m_animDelta =0;

        if(m_animFrame > 2){
            m_animFrame =0;
        }
    }

    if(m_isUp){
        ya -= m_speedWalking;
    }

    if(m_isDown){
        ya += m_speedWalking;
    }

    if(m_isLeft){
        xa -= m_speedWalking;
    }

    if(m_isRight){
        xa += m_speedWalking;
    }

    if(xa != 0 || ya != 0){
        m_isWalking = true;
        move(xa,ya);
    }else{
        m_isWalking = false;
    }

    m_animTime = 10;

}

/**
 * @brief Player::boundingRect
 * @return
 */
QRectF PlayerSound::boundingRect() const
{
    return QRect(0,0,m_pWidth,m_pHeight);
}

/**
 * @brief Player::move
 * @param xa
 * @param ya
 */
void PlayerSound::move(int xa, int ya)
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
 * @brief Player::getWidth
 * @return
 */
int PlayerSound::getWidth() const
{
    return m_pWidth;
}

/**
 * @brief Player::getHeight
 * @return
 */
int PlayerSound::getHeight() const
{
    return m_pHeight;
}

/**
 * @brief Player::keyPressEvent
 * @param event
 */
void PlayerSound::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        m_isUp = true;
    }

    if(event->key() == Qt::Key_Right){
        m_isRight = true;
    }
    if(event->key() == Qt::Key_Left){
        m_isLeft = true;
    }
    if(event->key() == Qt::Key_Down){
        m_isDown = true;}

    if(event->key() == Qt::Key_Space){
        m_isRun = true;}

}

/**
 * @brief Player::keyReleaseEvent
 * @param event
 */
void PlayerSound::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        m_isUp = false;
    }

    if(event->key() == Qt::Key_Right){
        m_isRight = false;
    }
    if(event->key() == Qt::Key_Left){
        m_isLeft = false;
    }
    if(event->key() == Qt::Key_Down){
        m_isDown = false;
    }

    if(event->key() == Qt::Key_Space){
        m_isRun = false;
    }
}
