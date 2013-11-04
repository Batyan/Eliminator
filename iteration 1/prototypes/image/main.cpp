#include <QApplication>
#include <QtWidgets>
#include"obj.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    QGraphicsScene scene;
    scene.setSceneRect(-400, -300, 800, 600);

    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    obj *o = new obj;
    o->setPos(::sin(6.28) * 200,
                      ::cos(6.28) * 200);
    scene.addItem(o);

    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(QPixmap("../protoDeplacementImage/img/background.jpg"));
//! [4] //! [5]
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::ScrollHandDrag);
//! [5] //! [6]
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Colliding Mice"));
    view.resize(800, 600);
    view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(1000 / 33);

    return app.exec();
}
