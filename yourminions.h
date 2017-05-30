#ifndef YOURMINIONS_H
#define YOURMINIONS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Yourminions:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Yourminions(QGraphicsItem *parent=0);
    double distance(QGraphicsItem *item);
    virtual void fire();
public slots:
    void aim_target();
protected:
    QGraphicsPolygonItem *attack_area;
    QPointF attack_destination;
    bool has_target;
};

#endif // YOURMINIONS_H
