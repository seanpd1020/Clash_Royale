#ifndef MYMINION1_H
#define MYMINION1_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "myminions.h"

class Myminion1:public Myminions
{
    Q_OBJECT
public:
    Myminion1(QGraphicsItem *parent=0);
    void fire();
public slots:
    void move();
    void aim_target();
};

#endif // MINION1_H
