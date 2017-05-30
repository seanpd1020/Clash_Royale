#ifndef YOURMINION8_H
#define YOURMINION8_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "yourminions.h"

class Yourminion8:public Yourminions
{
    Q_OBJECT
public:
    Yourminion8(QGraphicsItem *parent=0);
    void fire();
public slots:
    void move();
    void aim_target();
};

#endif // YOURMINION8_H
