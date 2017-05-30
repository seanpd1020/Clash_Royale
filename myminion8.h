#ifndef MYMINION8_H
#define MYMINION8_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "myminions.h"

class Myminion8:public Myminions
{
    Q_OBJECT
public:
    Myminion8(QGraphicsItem *parent=0);
    void fire();
public slots:
    void move();
    void aim_target();
};

#endif // MYMINION8_H
