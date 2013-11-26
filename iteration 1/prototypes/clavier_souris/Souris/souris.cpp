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

void Souris::mouseDoubleClickEvent ( QMouseEvent * event )
{
    if(event->button() == Qt::LeftButton)
    {
        qWarning("double clic gauche");
    }
}

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
