/**
 * \file clavier.cpp
 * \brief Fichier clavier.cpp.
 * \author Michael Plong
 * \version 1.0
 * \date 02 novembre 2013
 *
 *
 */

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

 	/*!
     *  \brief Fonction keyPressEvent
     *
     *  Fonction appelé à chaque fois qu'une touche est enfoncée
		et une nouvelle fois quand une touche est restée maintenue suffisamment longtemps.
     *
     *  \param event : la fonction prend un QKeyEvent en parametre.
	 *
     */
void Clavier::keyPressEvent(QKeyEvent *event)
{
    qDebug() << event->key();

        switch (event->key())
        {
         case Qt::Key_Left:
            //upPressed = true;
            event->accept();
            qWarning("key_Left Press!!");/*!< fleche gauche presser */
             break;
         case Qt::Key_Right:
            //upPressed = true;
            event->accept();
            qWarning("key_Right Press!!");/*!< fleche droite presser */
             break;
         case Qt::Key_Down:
            //upPressed = true;
            event->accept();
            qWarning("key_Down Press!!");/*!< fleche bas presser */
             break;
         case Qt::Key_Up:
            //upPressed = true;
            event->accept();
            qWarning("key_Up Press!!");/*!< fleche haute presser */
             break;
         case Qt::Key_Escape:   
            close();
         default: QWidget::keyPressEvent(event);
             break;
        }

}
	/*!
     *  \brief Fonction keyPressEvent
     *
     *  Fonction appelé à chaque fois qu'une touche est relâchée et tant qu'elle est maintenue enfoncée.
     *
     *  \param event : la fonction prend un QKeyEvent en parametre.
	 *
     */
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
