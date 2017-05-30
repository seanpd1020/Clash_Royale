#ifndef YOURMINION2_H
#define YOURMINION2_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "yourminions.h"

class Yourminion2:public Yourminions
{
    Q_OBJECT
public:
    Yourminion2(QGraphicsItem *parent=0);
    void fire();
public slots:
    void move();
    void aim_target();
};

#endif // YOURMINION2_H
