#include "mybuilding.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QLineF>
#include "game.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include "yourminions.h"
#include "shell.h"

extern Game *game;

Mybuilding::Mybuilding(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    QVector<QPointF> point;
    point << QPoint(2,0) << QPoint(4,0) << QPoint(6,2) << QPoint(6,4) << QPoint(4,6) << QPoint(2,6) << QPoint(0,4) << QPoint(0,2);
    int factor = 75;
    for (size_t i = 0, n = point.size(); i < n; i++){
        point[i] = factor*point[i];
    }

    attack_area = new QGraphicsPolygonItem(QPolygonF(point),this);

    QPointF poly_center(1.5,1.5);
    poly_center = factor*poly_center;
    poly_center = mapToScene(poly_center);
    QPointF tower_center(x(),y());
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());

    attack_destination = QPointF(0,0);
    has_target = false;
}
double Mybuilding::distance(QGraphicsItem *item)
{
    QLineF ln(this->pos(),item->pos());
    return ln.length();
}
void Mybuilding::fire()
{
    Shell *shell=new Shell();
    shell->setPos(x()+50,y()+50);
    QLineF ln(QPointF(x()+50,y()+50),attack_destination);
    int angle = -1 * ln.angle();
    shell->setRotation(angle);
    game->scene->addItem(shell);
}
void Mybuilding::aim_target()
{
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();
    has_target = false;
    double closest_distance = 600;
    QPointF closest_point(50,50);
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i)
    {
        Yourminions * m = dynamic_cast<Yourminions *>(colliding_items[i]);

        if (m)
        {
            double this_distance = distance(colliding_items[i]);
            if (this_distance < closest_distance){
                closest_distance = this_distance;
                closest_point = colliding_items[i]->pos();
                has_target = true;
            }
        }
    }

    if (has_target){
        attack_destination = closest_point;
        fire();
    }
}
