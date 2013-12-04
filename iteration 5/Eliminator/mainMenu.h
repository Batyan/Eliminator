#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QListWidget>
#include <QTextEdit>
#include <QLabel>
#include <QMenuBar>
#include <QToolBar>
#include <QDesktopWidget>
#include <QApplication>
#include "gameview.h"
#include "gamewindow.h"
#include <qmenubar.h>
#include <qmenu.h>
#include <QDir>


class GameView;
class Gamewindow;

class mainMenu : public QMainWindow
{
    Q_OBJECT
public:
    explicit mainMenu();

public slots:

    void showSoloMenu();
    void hideSoloMenu();

    void showMultiMenu();
    void hideMultiMenu();

    void showOptionMenu();
    void hideOptionMenu();

    void showLoadMenu();
    void hideLoadMenu();

    void showCreateMenu();
    void hideCreateMenu();

    void showJoinMenu();
    void hideJoinMenu();

    // se connecte à une partie multi
    void GameMulticonnect();

    // créer une partie multi
    void GameMultiCreate();

    // créer une partie solo
    void GameSoloCreate();

    // charge une partie solo
    void GameSoloLoad();

    // Nouvelle partie
    void on_single_clicked();

    //mode plein ecran
    void fullscreen();

    //retour vers menu principale
    void backMainMenu();

public:
    QWidget *m_layout;
    QWidget *m_mainMenu;
    QPushButton *m_btn0;
    QPushButton *m_btn1;
    QPushButton *m_btn2;
    QPushButton *m_btn3;
    QLabel *m_title;

    QWidget *m_solo;
    QPushButton *m_newGame;
    QPushButton *m_loadGame;
    QPushButton *m_soloBack;

    QWidget *m_multi;
    QLabel * m_printer;
    QPushButton *m_multiBack;

    QWidget *m_option;
    QPushButton *m_fullsize;
    QPushButton *m_optionBack;

    QWidget *m_loadMenu;
    QListWidget *m_listSvg;
    QWidget *m_lmbox;
    QPushButton *m_loadSvg;
    QPushButton *m_loadBack;

    QWidget *m_creatMenu;
    QListWidget *m_listLvl;
    QWidget *m_llbox;
    QPushButton *m_loadlvl;
    QPushButton *m_creatBack;

    QWidget *m_joinMenu;
    QTextEdit *m_ipadr;
    QWidget *m_cbox;
    QPushButton *m_connect;
    QPushButton *m_joinBack;

    GameWindow *m_gameWin;
    QWidget *m_image;


    // charge l'UI en ram et affiche le menu principale
    void initMenu();
    // cache le menu principale
    void hideMenu();
    // affiche le menu principale
    void showMenu();


};

#endif // GAMEWIND_H
