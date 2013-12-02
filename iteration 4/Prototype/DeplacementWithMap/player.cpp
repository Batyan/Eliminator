
#include <QPainter>
#include <QKeyEvent>

#include "player.h"
#include "directionmove.h"


Player::Player()
    :MovableEntity(150,150,DEFAULT_P_WIDTH,DEFAULT_P_HEIGHT)

{
    /*On donne un sprite par defaut à notre player*/
    setPSpriteMove(new SpriteImgMove(":res/characters.png"));

    /*On définie que player est focusable et peut resevoir des signaux envoyer par la scène.*/
    setFlag(QGraphicsItem::ItemIsFocusable);

    /*On définie que player est l'objet qui possède le focus des events envoyer par la scène.*/
    setFocus();
}

Player::Player(qreal x, qreal y, QString crustomPathSprite)
    :MovableEntity(x,y,DEFAULT_P_WIDTH,DEFAULT_P_HEIGHT)
{

    /*On Donne un sprite à notre player,
       *si aucun chemin est définie c'est le sprite par défaut qui sera pris.*/
    if(crustomPathSprite.isNull()){
        setPSpriteMove(new SpriteImgMove(":res/characters.png"));
    }else{
        setPSpriteMove(new SpriteImgMove(crustomPathSprite));
    }

    /*On définie que player est focusable et peut resevoir des signaux envoyer par la scène.*/
    setFlag(QGraphicsItem::ItemIsFocusable);

    /*On définie que player est l'objet qui possède le focus des events envoyés par la scène.*/
    setFocus();

}


void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);
    getPSpriteMove()->render(0,0,getWidth(),getHeight(),painter,getDirMove(),getAnimFrame());

}

void Player::advance(int phase)
{
    if(!phase) return;

    qreal xa = 0, ya =0;

    setAnimDelta(getAnimDelta()+1);
    setAnimTime(getAnimTime()+ getSpeedWalking());

    /* On gère l'animation de déplacement */
    if(getAnimDelta() >= getAnimTime()){
        setAnimFrame(getAnimFrame()+1);
        setAnimDelta(0);

        if(getAnimFrame() > DEFAULT_ANIME_FRAME){
            setAnimFrame(0);
        }
    }

    /*On définie les coordonnées de déplacement
     *par rapport au sens où le player doit aller.*/
    if(getPSpriteMove()->getIsLookingUp()){
        ya -= getSpeedWalking();
    }

    if(getPSpriteMove()->getIsLookingDown()){
        ya += getSpeedWalking();
    }

    if(getPSpriteMove()->getIsLookingLeft()){
        xa -= getSpeedWalking();
    }

    if(getPSpriteMove()->getIsLookingRight()){
        xa += getSpeedWalking();
    }

    /* On effectue le déplacement du player*/
    if(xa != 0 || ya != 0){
        getPSpriteMove()->setIsWalking(true);
        move(xa,ya);
    }else{
        getPSpriteMove()->setIsWalking(false);
    }


    setAnimTime(DEFAULT_ANIME_TIME);
}

QRectF Player::boundingRect() const
{
    return QRectF (0,0,getWidth(),getHeight());
}

QPainterPath Player::shape() const
{
    QPainterPath path;
    path.addRect(0,0,getWidth(),getHeight());
    return path;
}

void Player::move(qreal xa, qreal ya)
{
    /*Permet de prendre en charge la diagonale et
     *la detection de la collision qui en découle*/
    if(xa != 0 && ya != 0){
        move(xa,0);
        move(0,ya);
        return;
    }

    /* On définie le sens de déplacement*/
    if(ya > 0){
        setDirMove(DIR_DOWN_MOVING);
    }

    if(ya < 0){
        setDirMove(DIR_UP_MOVING);
    }

    if(xa > 0){
        setDirMove(DIR_RIGHT_MOVING);
    }

    if(xa < 0){
        setDirMove(DIR_LEFT_MOVING);
    }

    if(!IsInCollision())
        setPos(mapToScene(xa,ya));


}


void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        getPSpriteMove()->setIsLookingUp(true);
    }
    if(event->key() == Qt::Key_Right){
        getPSpriteMove()->setIsLookingRight(true);
    }
    if(event->key() == Qt::Key_Left){
        getPSpriteMove()->setIsLookingLeft(true);
    }
    if(event->key() == Qt::Key_Down){
        getPSpriteMove()->setIsLookingDown(true);
    }

}


void Player::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        getPSpriteMove()->setIsLookingUp(false);
    }
    if(event->key() == Qt::Key_Right){
        getPSpriteMove()->setIsLookingRight(false);
    }
    if(event->key() == Qt::Key_Left){
        getPSpriteMove()->setIsLookingLeft(false);
    }
    if(event->key() == Qt::Key_Down){
        getPSpriteMove()->setIsLookingDown(false);
    }
}

