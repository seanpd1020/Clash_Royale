#ifndef MYMINION4_H
#define MYMINION4_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "myminions.h"

class Myminion4:public Myminions
{
    Q_OBJECT
public:
    Myminion4(QGraphicsItem *parent=0);
    void fire();
public slots:
    void move();
    void aim_target();
};

#endif // MINION4_H
