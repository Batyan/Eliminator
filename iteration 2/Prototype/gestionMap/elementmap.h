#ifndef ELEMENTMAP_H
#define ELEMENTMAP_H

#include <QWidget>
#include <QVariant>
#include <QString>

class elementMap : public QWidget
{
    Q_OBJECT
public:
    elementMap(elementMap const& cp);
    elementMap(int x, int y,int type, QWidget *parent = 0);
    elementMap(QWidget *parent = 0);

    /* Cette fonction permet de savoir apres une deserialization
     * si l'objet est valide */
    bool isValide();

    // info sur l'objet
    QString virtual print();

    // serial de l'objet
    QVariant virtual serial();
    
signals:
    
public slots:

public:
    int m_x;
    int m_y;
    int m_type;
    
};

Q_DECLARE_METATYPE(elementMap);

/* on redéfinit les operateurs de flux pour l'object QDataStream
 * cela nous permet de sotcker et recuperer les objets serialisés dans un fihier */
QDataStream & operator << (QDataStream & out, const elementMap & Valeur);
QDataStream & operator >> (QDataStream & in, elementMap & Valeur);

#endif // ELEMENTMAP_H
