#ifndef YOURMINION3_H
#define YOURMINION3_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "yourminions.h"

class Yourminion3:public Yourminions
{
    Q_OBJECT
public:
    Yourminion3(QGraphicsItem *parent=0);
    void fire();
public slots:
    void move();
    void aim_target();
};

#endif // YOURMINION3_H
