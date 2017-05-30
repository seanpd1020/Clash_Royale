#ifndef YOURMINION5_H
#define YOURMINION5_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "yourminions.h"

class Yourminion5:public Yourminions
{
    Q_OBJECT
public:
    Yourminion5(QGraphicsItem *parent=0);
    void fire();
public slots:
    void move();
    void aim_target();
};

#endif // YOURMINION5_H
