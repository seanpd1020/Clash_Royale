#ifndef YOURMINION4_H
#define YOURMINION4_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "yourminions.h"

class Yourminion4:public Yourminions
{
    Q_OBJECT
public:
    Yourminion4(QGraphicsItem *parent=0);
    void fire();
public slots:
    void move();
    void aim_target();
};

#endif // YOURMINION4_H
