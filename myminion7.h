#ifndef MYMINION7_H
#define MYMINION7_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "myminions.h"

class Myminion7:public Myminions
{
    Q_OBJECT
public:
    Myminion7(QGraphicsItem *parent=0);
    void fire();
public slots:
    void move();
    void aim_target();
};

#endif // MYMINION7_H
