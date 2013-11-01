#include "myobject.h"

MyObject::MyObject(QObject *parent) :
    QObject(parent)
{
    id=0;
    pseudo="oduesp";
    message="egassem";
}

QString MyObject::getMessage() {
    return message;
}

QString MyObject::getPseudo() {
    return pseudo;
}

qint16 MyObject::getId() {
    return id;
}

void MyObject::setId(qint16 id) {
    this->id = id;
}

void MyObject::setPseudo(QString pseudo) {
    this->pseudo = pseudo;
}

void MyObject::setMessage(QString message) {
    this->message = message;
}
