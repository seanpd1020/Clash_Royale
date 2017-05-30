#include "yourminion6.h"
#include "mybuilding.h"
#include "myminions.h"
#include <QPixmap>
#include <QTimer>

Yourminion6::Yourminion6(QGraphicsItem *parent)
{
    QPixmap p;p.load(":/image/character6(flip).png");
    qreal width = p.width();qreal height = p.height();
    p=p.scaled(width/5,height/5,Qt::KeepAspectRatio);
    setPixmap(p);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(timer,SIGNAL(timeout()),this,SLOT(aim_target()));
    timer->start(100);
}
void Yourminion6::aim_target()
{
    QList<QGraphicsItem *> colliding_items1 = attack_area->collidingItems();
    QList<QGraphicsItem *> colliding_items2 = attack_area->collidingItems();
    has_target = false;
    double closest_distance = 300;
    QPointF closest_point(50,50);
    for (size_t i = 0, n = colliding_items1.size(); i < n; ++i)
    {
        Mybuilding * b = dynamic_cast<Mybuilding *>(colliding_items1[i]);

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
        Myminions * m = dynamic_cast<Myminions *>(colliding_items1[i]);

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
        setPos(x()+10,y());
    }
}
void Yourminion6::fire()
{
    Yourminions::fire();
}
void Yourminion6::move()
{
    if(pos().x()<250&&pos().y()>350)setPos(x(),y()-10);
    else if(pos().x()<250&&pos().y()<350)setPos(x(),y()+10);
    else setPos(x()-10,y());
}
