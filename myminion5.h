#ifndef MYMINION5_H
#define MYMINION5_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "myminions.h"

class Myminion5:public Myminions
{
    Q_OBJECT
public:
    Myminion5(QGraphicsItem *parent=0);
    void fire();
public slots:
    void move();
    void aim_target();
};

#endif // MYMINION5_H
