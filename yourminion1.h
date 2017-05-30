#ifndef YOURMINION1_H
#define YOURMINION1_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "yourminions.h"

class Yourminion1:public Yourminions
{
    Q_OBJECT
public:
    Yourminion1(QGraphicsItem *parent=0);
    void fire();
public slots:
    void move();
    void aim_target();
};

#endif // YOURMINION1_H
