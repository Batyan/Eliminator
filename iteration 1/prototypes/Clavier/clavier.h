#ifndef CLAVIER_H
#define CLAVIER_H

#include <QWidget>
#include <QKeyEvent>

namespace Ui {
class Clavier;
}

class Clavier : public QWidget
{
    Q_OBJECT

public:
    explicit Clavier(QWidget *parent = 0);
    ~Clavier();
 protected:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

private:
    Ui::Clavier *ui;
};

#endif // CLAVIER_H
