#ifndef MYMINION10_H
#define MYMINION10_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "myminions.h"

class Myminion10:public Myminions
{
    Q_OBJECT
public:
    Myminion10(QGraphicsItem *parent=0);
    void fire();
public slots:
    void move();
    void aim_target();
};

#endif // MYMINION10_H
