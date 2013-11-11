#include "mainwindow.h"
#include "scene.h"
#include "elementmap.h"
#include "mur.h"
#include "personnage.h"
#include "sauvegarde.h"
#include <QApplication>
#include <QDebug>
#include <QSettings>
#include <QVariant>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QVector<elementMap*> listElement;

    // infos pour le compilop
    qRegisterMetaTypeStreamOperators<elementMap>("elementMap");
    qRegisterMetaTypeStreamOperators<mur>("mur");
    qRegisterMetaTypeStreamOperators<personnage>("personnage");




    // pour effectuer des tests je créé un objet scene avec une liste d'éléments

    scene *gameScene = new scene();
    gameScene->listEleme.append(new personnage(5,5,1,100));
    gameScene->listEleme.append(new personnage(10,5,1,100));
    gameScene->listEleme.append(new personnage(15,5,1,100));
    gameScene->listEleme.append(new personnage(20,5,1,100));
    gameScene->listEleme.append(new personnage(25,5,1,100));
    gameScene->listEleme.append(new mur(1,1,0));
    gameScene->listEleme.append(new mur(2,2,0));
    gameScene->listEleme.append(new mur(3,3,0));


    // à partir de la liste des objets sur la scène on génère la map
    sauvegarde::storeMap("map1.ini",gameScene->listEleme);

    // à patir de la map on génère la map
    listElement = sauvegarde::restoreMap("map1.ini");

    //test
    for(int i=0;i<listElement.count();i++)
        qDebug() << listElement[i]->print();



    return a.exec();
}
