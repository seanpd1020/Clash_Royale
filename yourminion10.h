#ifndef YOURMINION10_H
#define YOURMINION10_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "yourminions.h"

class Yourminion10:public Yourminions
{
    Q_OBJECT
public:
    Yourminion10(QGraphicsItem *parent=0);
    void fire();
public slots:
    void move();
    void aim_target();
};

#endif // YOURMINION10_H
