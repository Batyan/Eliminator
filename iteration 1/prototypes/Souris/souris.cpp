/**
 * \file souris.cpp
 * \brief Fichier souris.cpp.
 * \author Michael Plong
 * \version 1.0
 * \date 02 novembre 2013
 *
 *
 */
#include "souris.h"
#include "ui_souris.h"
#include<iostream>


Souris::Souris(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Souris)
{
    ui->setupUi(this);
}

Souris::~Souris()
{
    delete ui;
}
 	/*!
     *  \brief Fonction mousePressEvent
     *
     *  Fonction appelé à chaque fois qu'il y a un click
	 *  Si ok, Affiche un message à l'ecran.
     *
     *  \param event : la fonction prend un QMouseEvent en parametre.
	 *
     */
void Souris::mousePressEvent ( QMouseEvent * event )
{
   std::cout << "Un clic a été fait à la position (" << event->x() << " , " << event->y() << " ) " << std::endl;

   switch (event->button())
   {
    case Qt::LeftButton:
        qWarning("clic gauche");
        break;
    case Qt::RightButton:
        qWarning("clic droit");
        break;
   default:
       QWidget::mousePressEvent(event);
       break;
   }
}
	 	/*!
     *  \brief Fonction mouseDoubleClickEvent 
     *
     *  Fonction appelé à chaque fois qu'un double click est reconnue.
	 *  Si ok, Affiche un message à l'ecran.
     *
     *  \param event : la fonction prend un QMouseEvent en parametre.
	 *
     */
void Souris::mouseDoubleClickEvent ( QMouseEvent * event )
{
    if(event->button() == Qt::LeftButton)
    {
        qWarning("double clic gauche");
    }
}
	 	/*!
     *  \brief Fonction mouseMoveEvent
     *
     *  Fonction appelé à chaque que la souris est en mouvement
	 *  Si ok, Affiche un message à l'ecran.
     *
     *  \param event : la fonction prend un QMouseEvent en parametre.
	 *
     */
void Souris::mouseMoveEvent ( QMouseEvent * event )
{
    qDebug("%d %d",event->pos().x(),event->pos().y());
    QWidget::mouseMoveEvent(event);
}

void Souris::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("text/plain"))
        event->acceptProposedAction();
}

void Souris::dropEvent(QDropEvent *event)
 {

     event->acceptProposedAction();
 }
