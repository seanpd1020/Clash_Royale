#ifndef MYMINION2_H
#define MYMINION2_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "myminions.h"

class Myminion2:public Myminions
{
    Q_OBJECT
public:
    Myminion2(QGraphicsItem *parent=0);
    void fire();
public slots:
    void move();
    void aim_target();
};

#endif // MINION2_H
