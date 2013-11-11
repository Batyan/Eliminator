/**
 * \file clavier.h
 * \brief Fichier clavier.h.
 * \author Michael Plong
 * \version 1.0
 * \date 02 novembre 2013
 *
 *
 */

#ifndef CLAVIER_H
#define CLAVIER_H

#include <QWidget>
#include <QKeyEvent>

namespace Ui {
class Clavier;
}

	  /*! \class clavier
	   * \brief classe clavier
	   *
	   *  La classe 
	   */
class Clavier : public QWidget
{
    Q_OBJECT

public:
    explicit Clavier(QWidget *parent = 0);
	/*!
     *  \brief Destructeur par defaut
     *
     *  Destructeur par defaut de la classe clavier     *
     */
    ~Clavier();
 protected:
 	/*!
     *  \brief Fonction keyPressEvent
     *
     *  Fonction appelé à chaque fois qu'une touche est enfoncée
		et une nouvelle fois quand une touche est restée maintenue suffisamment longtemps.
     *
     *  \param event : la fonction prend un QKeyEvent en parametre.
	 *
     */
    void keyPressEvent(QKeyEvent* event);
	/*!
     *  \brief Fonction keyPressEvent
     *
     *  Fonction appelé à chaque fois qu'une touche est relâchée et tant qu'elle est maintenue enfoncée.
     *
     *  \param event : la fonction prend un QKeyEvent en parametre.
	 *
     */
    void keyReleaseEvent(QKeyEvent* event);

private:
    Ui::Clavier *ui;
};

#endif // CLAVIER_H
