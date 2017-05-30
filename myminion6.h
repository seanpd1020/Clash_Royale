#ifndef MYMINION6_H
#define MYMINION6_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "myminions.h"

class Myminion6:public Myminions
{
    Q_OBJECT
public:
    Myminion6(QGraphicsItem *parent=0);
    void fire();
public slots:
    void move();
    void aim_target();
};

#endif // MYMINION6_H
