#ifndef YOURMINION9_H
#define YOURMINION9_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "yourminions.h"

class Yourminion9:public Yourminions
{
    Q_OBJECT
public:
    Yourminion9(QGraphicsItem *parent=0);
    void fire();
public slots:
    void move();
    void aim_target();
};

#endif // YOURMINION9_H
