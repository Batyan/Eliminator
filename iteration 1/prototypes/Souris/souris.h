/**
 * \file souris.h
 * \brief Fichier souris.h.
 * \author Michael Plong
 * \version 1.0
 * \date 02 novembre 2013
 *
 *
 */

#ifndef SOURIS_H
#define SOURIS_H

#include <QWidget>
#include <QMouseEvent>
#include<QMimeData>

namespace Ui {
class Souris;
}
	  /*! \class souris
	   * \brief classe souris
	   *
	   *  La classe 
	   */
class Souris : public QWidget
{
    Q_OBJECT

public:
    explicit Souris(QWidget *parent = 0);
		/*!
     *  \brief Destructeur par defaut
     *
     *  Destructeur par defaut de la classe souris
     *
     */
    ~Souris();
protected:
 	/*!
     *  \brief Fonction mousePressEvent
     *
     *  Fonction appelé à chaque fois qu'il y a un click
     *
     *  \param event : la fonction prend un QMouseEvent en parametre.
	 *
     */
    void mousePressEvent ( QMouseEvent * event );
	 	/*!
     *  \brief Fonction mouseDoubleClickEvent 
     *
     *  Fonction appelé à chaque fois qu'un double click est reconnue
     *
     *  \param event : la fonction prend un QMouseEvent en parametre.
	 *
     */
    void mouseDoubleClickEvent ( QMouseEvent * event );
	 	/*!
     *  \brief Fonction mouseMoveEvent
     *
     *  Fonction appelé à chaque que la souris est en mouvement
     *
     *  \param event : la fonction prend un QMouseEvent en parametre.
	 *
     */
    void mouseMoveEvent ( QMouseEvent * event );
    //void mouseReleaseEvent ( QMouseEvent * event );
    //void wheelEvent ( QWheelEvent * event );//évènements molette
    void dropEvent(QDropEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
private:
    Ui::Souris *ui;
};

#endif // SOURIS_H
