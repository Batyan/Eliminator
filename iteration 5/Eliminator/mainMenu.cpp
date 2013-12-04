#include "mainMenu.h"
#include <qmenubar.h>
#include <qmenu.h>
#include <QMainWindow>

mainMenu::mainMenu()
{
    setGeometry(0,0,640,380);
    QDesktopWidget* bureau = QApplication::desktop();
    int x = (bureau->screenGeometry(bureau->primaryScreen()).width()/2) - (width()/2);
    int y = (bureau->screenGeometry(bureau->primaryScreen()).height()/2) - (height()/2);
    move(x,y);

    /*On donne un titre à notre fenêtre.*/
    setWindowTitle("ELIMINATOR++");
    setStyleSheet("background-color: black;color:white;");


}

void mainMenu::initMenu(){

    //delete layout();


    QMenu *file = menuBar()->addMenu(tr("&Menu"));
    file->setStyleSheet("QMenu::item:selected{color:blue;}");
    QMenu *game = file->addMenu("Jeu");
    game->setStyleSheet("QMenu::item:selected{color:blue;}");
    QAction *newAction = game->addAction(tr("menu principal"));

    newAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));

    QAction *quitAction = file->addAction(tr("Quit"));
    quitAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));

    QMenu *option = menuBar()->addMenu(tr("&Option"));
    option->setStyleSheet("QMenu::item:selected{color:blue;}");
    QMenu *reglage = option->addMenu("Réglage");
    reglage->setStyleSheet("QMenu::item:selected{color:blue;}");
    QAction *sizeAction = reglage->addAction(tr("Mode Plein écran"));
    sizeAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_F9));

    QAction *miniAction = reglage->addAction(tr("Réduire Plein écran"));
    miniAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_F10));

    QObject::connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(newAction, SIGNAL(triggered()), this, SLOT(backMainMenu()));
    connect(sizeAction, SIGNAL(triggered()), this, SLOT(fullscreen()));
    connect(miniAction, SIGNAL(triggered()), this, SLOT(miniscreen()));

    m_layout = new QWidget(this);
    setCentralWidget(m_layout);

    m_image = new QWidget(this);
    m_image->setGeometry(0,0,720,120);
    m_image->setStyleSheet("background-image: url(:/res/elim_v3.png);""background-position: top center; "
                           "background-repeat: no-repeat;"
                           "background-color: black;color:white;");



    m_mainMenu = new QWidget(this);
    m_mainMenu->setFixedHeight(150);
    m_mainMenu->setFixedWidth(220);
    m_btn0 = new QPushButton("partie solo");
    m_btn1 = new QPushButton("règles");
    m_btn3 = new QPushButton("option");
    m_btn2 = new QPushButton("quitter");


    m_solo = new QWidget();
    m_solo->setFixedHeight(150);
    m_solo->setFixedWidth(220);
    m_newGame = new QPushButton("nouvelle partie");
    m_loadGame = new QPushButton("charger une partie");
    m_soloBack = new QPushButton("retour");


    m_multi = new QWidget();
    m_multi->setFixedHeight(150);
    m_multi->setFixedWidth(400);
    m_printer = new QLabel("Deplacez vous à l'aide des touches directionnelles\net tirez sur les ennemies les plus proches à l'aide\ndu clic droit de la souris");
    m_multiBack = new QPushButton("retour");

    m_option = new QWidget();
    m_option->setFixedHeight(150);
    m_option->setFixedWidth(220);
    m_fullsize = new QPushButton("Plein ecran");
    m_optionBack = new QPushButton("retour");


    m_loadMenu = new QWidget();
    m_loadMenu->setFixedHeight(190);
    m_loadMenu->setFixedWidth(400);
    m_lmbox = new QWidget();
    m_listSvg = new QListWidget();

    QDir LvlFolder1(":res/level");
    QFileInfoList list1 = LvlFolder1.entryInfoList();
    for (int i = 0; i < list1.size(); ++i)
        new QListWidgetItem(list1.at(i).fileName(), m_listSvg);
    m_loadSvg = new QPushButton("charger une partie");
    m_loadBack = new QPushButton("retour");


    m_creatMenu = new QWidget();
    m_creatMenu->setFixedHeight(200);
    m_creatMenu->setFixedWidth(400);
    m_llbox = new QWidget();
    m_listLvl = new QListWidget();

    QDir LvlFolder2(":res/level");
    QFileInfoList list2 = LvlFolder2.entryInfoList();
    for (int i = 0; i < list2.size(); ++i)
        new QListWidgetItem(list2.at(i).fileName(), m_listLvl);

    m_loadlvl = new QPushButton("créer la partie");
    m_creatBack = new QPushButton("retour");

    m_joinMenu = new QWidget();
    m_joinMenu->setFixedHeight(110);
    m_joinMenu->setFixedWidth(400);
    m_cbox = new QWidget();
    m_ipadr = new QTextEdit("entrez addresse ip!");
    m_connect = new QPushButton("se connecter");
    m_joinBack = new QPushButton("retour");

    QString style("QPushButton {  background-color: black;"
                  "color:white;"
                  "border-style: outset;"
                  "border-width: 5px;"
                  "border-radius: 7px;"
                  "border-color:  #496B8C;"
                  "height:25px"
                  "}"

                  "QPushButton:hover{background-color: #12375C;}");

    m_listSvg->setFixedHeight(130);
    m_listLvl->setFixedHeight(130);
    m_ipadr->setFixedHeight(30);

    m_btn0->setStyleSheet(style);
    m_btn1->setStyleSheet(style);
    m_btn2->setStyleSheet(style);
    m_btn3->setStyleSheet(style);
    m_newGame->setStyleSheet(style);
    m_loadGame->setStyleSheet(style);
    m_soloBack->setStyleSheet(style);
    m_printer->setStyleSheet(style);
    m_multiBack->setStyleSheet(style);
    m_loadSvg->setStyleSheet(style);
    m_loadBack->setStyleSheet(style);
    m_loadlvl->setStyleSheet(style);
    m_creatBack->setStyleSheet(style);
    m_connect->setStyleSheet(style);
    m_joinBack->setStyleSheet(style);
    m_fullsize->setStyleSheet(style);
    m_optionBack->setStyleSheet(style);


    //def du menu principal
    QHBoxLayout *Hlayout = new QHBoxLayout();
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(m_btn0);
    mainLayout->addWidget(m_btn1);
    mainLayout->addWidget(m_btn3);
    mainLayout->addWidget(m_btn2);
    m_mainMenu->setLayout(mainLayout);

    //def du menu solo
    QVBoxLayout *soloLayout = new QVBoxLayout();
    soloLayout->addWidget(m_newGame);
    soloLayout->addWidget(m_loadGame);
    soloLayout->addWidget(m_soloBack);
    m_solo->setLayout(soloLayout);

    //def du menu multi
    QVBoxLayout *multiLayout = new QVBoxLayout();
    multiLayout->addWidget(m_printer);
    multiLayout->addWidget(m_multiBack);
    m_multi->setLayout(multiLayout);

    //def du menu option
    QVBoxLayout *optionLayout = new QVBoxLayout();
    optionLayout->addWidget(m_fullsize);
    optionLayout->addWidget(m_optionBack);
    m_option->setLayout(optionLayout);

    //def du menu load Svg
    QVBoxLayout *lsvgLayout = new QVBoxLayout();
    QHBoxLayout *hsvgLayout =new QHBoxLayout();
    hsvgLayout->addWidget(m_loadSvg);
    hsvgLayout->addWidget(m_loadBack);
    m_lmbox->setLayout(hsvgLayout);

    lsvgLayout->addWidget(m_listSvg);
    lsvgLayout->addWidget(m_lmbox);
    m_loadMenu->setLayout(lsvgLayout);


    //def du menu creat map
    QVBoxLayout *lcrtLayout = new QVBoxLayout();
    QHBoxLayout *hcrtLayout =new QHBoxLayout();
    hcrtLayout->addWidget(m_loadlvl);
    hcrtLayout->addWidget(m_creatBack);
    m_llbox->setLayout(hcrtLayout);

    lcrtLayout->addWidget(m_listLvl);
    lcrtLayout->addWidget(m_llbox);
    m_creatMenu->setLayout(lcrtLayout);

    //def du menu creat map
    QVBoxLayout *ljoinLayout = new QVBoxLayout();
    QHBoxLayout *hjoinLayout =new QHBoxLayout();
    hjoinLayout->addWidget(m_connect);
    hjoinLayout->addWidget(m_joinBack);
    m_cbox->setLayout(hjoinLayout);

    ljoinLayout->addWidget(m_ipadr);
    ljoinLayout->addWidget(m_cbox);
    m_joinMenu->setLayout(ljoinLayout);


    //chargement du menu principal
    Hlayout->addWidget(m_mainMenu);
    m_layout->setLayout(Hlayout);


    QObject::connect(m_btn0, SIGNAL(clicked()), this, SLOT(showSoloMenu()));
    QObject::connect(m_soloBack, SIGNAL(clicked()), this, SLOT(hideSoloMenu()));

    QObject::connect(m_btn1, SIGNAL(clicked()), this, SLOT(showMultiMenu()));
    QObject::connect(m_multiBack, SIGNAL(clicked()), this, SLOT(hideMultiMenu()));

    QObject::connect(m_btn3, SIGNAL(clicked()), this, SLOT(showOptionMenu()));
    QObject::connect(m_optionBack, SIGNAL(clicked()), this, SLOT(hideOptionMenu()));
    QObject::connect(m_fullsize, SIGNAL(clicked()), this, SLOT(showFullScreen()));
    QObject::connect(m_btn2, SIGNAL(clicked()), this, SLOT(close()));

    QObject::connect(m_loadGame, SIGNAL(clicked()), this, SLOT(showLoadMenu()));
    QObject::connect(m_loadBack, SIGNAL(clicked()), this, SLOT(hideLoadMenu()));

    QObject::connect(m_creatBack, SIGNAL(clicked()), this, SLOT(hideCreateMenu()));

    QObject::connect(m_joinBack, SIGNAL(clicked()), this, SLOT(hideJoinMenu()));


    // déclenche une connexion à une partie multi
    QObject::connect(m_connect, SIGNAL(clicked()), this, SLOT(GameMulticonnect()));

    // déclenche la création d'une partie partie multi
    QObject::connect(m_loadlvl, SIGNAL(clicked()), this, SLOT(GameMultiCreate()));

    // déclenche la création d'une partie partie solo
    QObject::connect(m_newGame, SIGNAL(clicked()), this, SLOT(GameSoloCreate()));

    // déclenche le chargement d'une partie partie solo
    QObject::connect(m_loadSvg, SIGNAL(clicked()), this, SLOT(GameSoloLoad()));

    // quitte l'application
    //connect(m_btn2, SIGNAL(triggered()), this, SLOT(quit()));


}

void mainMenu::hideMenu(){

    m_mainMenu->setVisible(false);

}


void mainMenu::showMenu(){

    delete m_layout->layout();

    m_mainMenu->setVisible(true);

    QHBoxLayout *Hlayout = new QHBoxLayout();

    Hlayout->addWidget(m_mainMenu);
    m_layout->setLayout(Hlayout);

}

void mainMenu::showSoloMenu(){

    delete m_layout->layout();
    hideMenu();

    m_solo->setVisible(true);

    QHBoxLayout *Hlayout = new QHBoxLayout();

    Hlayout->addWidget(m_solo);
    m_layout->setLayout(Hlayout);
}


void mainMenu::hideSoloMenu(){

    m_solo->setVisible(false);
    showMenu();

}

void mainMenu::showOptionMenu(){

    delete m_layout->layout();
    hideMenu();

    m_option->setVisible(true);

    QHBoxLayout *Hlayout = new QHBoxLayout();

    Hlayout->addWidget(m_option);
    m_layout->setLayout(Hlayout);
}


void mainMenu::hideOptionMenu(){

    m_option->setVisible(false);
    showMenu();

}

void mainMenu::hideMultiMenu(){

    m_multi->setVisible(false);
    showMenu();

}


void mainMenu::showMultiMenu(){

    delete m_layout->layout();
    hideMenu();

    m_multi->setVisible(true);

    QHBoxLayout *Hlayout = new QHBoxLayout();

    Hlayout->addWidget(m_multi);
    m_layout->setLayout(Hlayout);
}

void mainMenu::hideLoadMenu(){

    m_loadMenu->setVisible(false);
    showSoloMenu();

}


void mainMenu::showLoadMenu(){

    delete m_layout->layout();
    m_solo->setVisible(false);

    m_loadMenu->setVisible(true);

    QHBoxLayout *Hlayout = new QHBoxLayout();

    Hlayout->addWidget(m_loadMenu);
    m_layout->setLayout(Hlayout);
}

void mainMenu::hideCreateMenu(){

    m_creatMenu->setVisible(false);
    showMultiMenu();

}


void mainMenu::showCreateMenu(){

    delete m_layout->layout();
    m_multi->setVisible(false);

    m_creatMenu->setVisible(true);

    QHBoxLayout *Hlayout = new QHBoxLayout();

    Hlayout->addWidget(m_creatMenu);
    m_layout->setLayout(Hlayout);
}

void mainMenu::hideJoinMenu(){

    m_joinMenu->setVisible(false);
    showMultiMenu();

}


void mainMenu::showJoinMenu(){

    delete m_layout->layout();
    m_multi->setVisible(false);

    m_joinMenu->setVisible(true);

    QHBoxLayout *Hlayout = new QHBoxLayout();

    Hlayout->addWidget(m_joinMenu);
    m_layout->setLayout(Hlayout);
}

void mainMenu::GameMulticonnect(){

}

void mainMenu::GameMultiCreate(){

    // choix du niveau
    qDebug() << m_listLvl->currentRow();

    // code à ecrire
}

void mainMenu::GameSoloCreate(){

    delete m_layout->layout();
    m_solo->setVisible(false);
    m_image->setVisible(false);

    m_gameWin = new GameWindow();
    QHBoxLayout *Hlayout = new QHBoxLayout();

    Hlayout->addWidget(m_gameWin);
    m_layout->setLayout(Hlayout);

}

void mainMenu::GameSoloLoad(){

    delete m_layout->layout();
    m_image->setVisible(false);

    m_gameWin = new GameWindow(m_listSvg->currentRow()+1);
    QHBoxLayout *Hlayout = new QHBoxLayout();

    Hlayout->addWidget(m_gameWin);
    m_layout->setLayout(Hlayout);
}

void mainMenu::on_single_clicked(){

    delete m_layout->layout();

    m_gameWin = new GameWindow();
    QHBoxLayout *Hlayout = new QHBoxLayout();

    Hlayout->addWidget(m_gameWin);
    m_layout->setLayout(Hlayout);

}

void mainMenu::fullscreen(){
    showFullScreen();
}

void mainMenu::miniscreen()
{
    showNormal();
}

void mainMenu::backMainMenu(){

    delete m_gameWin;
    m_image->setVisible(true);
    showMenu();


}
