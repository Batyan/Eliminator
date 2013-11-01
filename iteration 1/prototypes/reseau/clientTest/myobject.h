#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>

class MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = 0);
    void setPseudo(QString pseudo);
    void setId(qint16 id);
    void setMessage(QString message);

    QString getMessage();
    QString getPseudo();
    qint16  getId();

private:
    qint16 id;
    QString pseudo;
    QString message;
};

#endif // MYOBJECT_H
