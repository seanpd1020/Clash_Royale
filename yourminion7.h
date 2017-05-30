#ifndef YOURMINION7_H
#define YOURMINION7_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "yourminions.h"

class Yourminion7:public Yourminions
{
    Q_OBJECT
public:
    Yourminion7(QGraphicsItem *parent=0);
    void fire();
public slots:
    void move();
    void aim_target();
};

#endif // YOURMINION7_H
