#ifndef MYMINION3_H
#define MYMINION3_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "myminions.h"

class Myminion3:public Myminions
{
    Q_OBJECT
public:
    Myminion3(QGraphicsItem *parent=0);
    void fire();
public slots:
    void move();
    void aim_target();
};

#endif // MINION3_H
