#ifndef SOURIS_H
#define SOURIS_H

#include <QWidget>
#include <QMouseEvent>
#include<QMimeData>

namespace Ui {
class Souris;
}

class Souris : public QWidget
{
    Q_OBJECT

public:
    explicit Souris(QWidget *parent = 0);
    ~Souris();
protected:
    void mousePressEvent ( QMouseEvent * event );
    void mouseDoubleClickEvent ( QMouseEvent * event );
    void mouseMoveEvent ( QMouseEvent * event );
    //void mouseReleaseEvent ( QMouseEvent * event );
    //void wheelEvent ( QWheelEvent * event );//évènements molette
    void dropEvent(QDropEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
private:
    Ui::Souris *ui;
};

#endif // SOURIS_H
