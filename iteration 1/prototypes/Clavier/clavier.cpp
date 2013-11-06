#include <QDebug>

#include "clavier.h"
#include "ui_clavier.h"

Clavier::Clavier(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Clavier)
{
    ui->setupUi(this);
}

Clavier::~Clavier()
{
    delete ui;
}

bool upPressed = false;

void Clavier::keyPressEvent(QKeyEvent *event)
{
    qDebug() << event->key();

    do{
        switch (event->key())
        {
         case Qt::Key_Left:
            //upPressed = true;
            event->accept();
            qWarning("key_Left Press!!");
             break;
         case Qt::Key_Right:
            //upPressed = true;
            event->accept();
            qWarning("key_Right Press!!");
             break;
         case Qt::Key_Down:
            //upPressed = true;
            event->accept();
            qWarning("key_Down Press!!");
             break;
         case Qt::Key_Up:
            //upPressed = true;
            event->accept();
            qWarning("key_Up Press!!");
             break;
         case Qt::Key_Escape:   // si c'est echape on quitte
            close();
         default: QWidget::keyPressEvent(event);
             break;
        }
    }
    while(upPressed);

}

void Clavier::keyReleaseEvent(QKeyEvent *event)
{
     if(event->key() == Qt::Key_Up)
     {
         upPressed = false;

     }
     else
     {
         event->ignore();
     }
     if(event->key() == Qt::Key_Down)
     {
         upPressed = false;

     }
     else
     {
         event->ignore();
     }
     if(event->key() == Qt::Key_Left)
     {
         upPressed = false;

     }
     else
     {
         event->ignore();
     }


   }
