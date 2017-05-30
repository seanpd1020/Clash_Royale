#include "myminions.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QLineF>
#include "game.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include "yourminions.h"
#include "yourbuilding.h"
#include "arrow.h"


extern Game *game;

Myminions::Myminions(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    QVector<QPointF> point;
    point << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3) << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    int factor = 75;
    for (size_t i = 0, n = point.size(); i < n; i++){
        point[i] = factor*point[i];
    }

    attack_area = new QGraphicsPolygonItem(QPolygonF(point),this);

    QPointF poly_center(1.5,1.5);
    poly_center = factor*poly_center;
    poly_center = mapToScene(poly_center);
    QPointF minion_center(x()+44,y()+44);
    QLineF ln(poly_center,minion_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());

    attack_destination = QPointF(0,0);
    has_target = false;
}
double Myminions::distance(QGraphicsItem *item)
{
    QLineF ln(this->pos(),item->pos());
    return ln.length();
}
void Myminions::fire()
{    
    Arrow *arrow=new Arrow();
    arrow->setPos(x()+90,y());
    QLineF ln(QPointF(x(),y()),attack_destination);
    int angle = -1 * ln.angle();
    arrow->setRotation(angle);
    game->scene->addItem(arrow);
}
void Myminions::aim_target()
{
    QList<QGraphicsItem *> colliding_items1 = attack_area->collidingItems();
    QList<QGraphicsItem *> colliding_items2 = attack_area->collidingItems();
    has_target = false;
    double closest_distance = 300;
    QPointF closest_point(50,50);
    for (size_t i = 0, n = colliding_items1.size(); i < n; ++i)
    {
        Yourbuilding * b = dynamic_cast<Yourbuilding *>(colliding_items1[i]);

        if (b)
        {
            double this_distance1 = distance(colliding_items1[i]);
            if (this_distance1 < closest_distance)
            {
                closest_distance = this_distance1;
                closest_point = colliding_items1[i]->pos();
                has_target = true;
            }
        }
    }
    for (size_t i = 0, n = colliding_items2.size(); i < n; ++i)
    {
        Yourminions * m = dynamic_cast<Yourminions *>(colliding_items1[i]);

        if (m)
        {
            double this_distance2 = distance(colliding_items2[i]);
            if (this_distance2 < closest_distance)
            {
                closest_distance = this_distance2;
                closest_point = colliding_items2[i]->pos();
                has_target = true;
            }
        }
    }
    if (has_target){
        attack_destination = closest_point;
        fire();
    }
}
