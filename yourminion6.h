#ifndef YOURMINION6_H
#define YOURMINION6_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "yourminions.h"

class Yourminion6:public Yourminions
{
    Q_OBJECT
public:
    Yourminion6(QGraphicsItem *parent=0);
    void fire();
public slots:
    void move();
    void aim_target();
};

#endif // YOURMINION6_H
