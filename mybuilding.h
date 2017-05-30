#ifndef MYBUILDING_H
#define MYBUILDING_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Mybuilding:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Mybuilding(QGraphicsItem *parent=0);
    double distance(QGraphicsItem *item);
    virtual void fire();
public slots:
    void aim_target();
protected:
    QGraphicsPolygonItem *attack_area;
    QPointF attack_destination;
    bool has_target;
};

#endif // MYBUILDING_H
