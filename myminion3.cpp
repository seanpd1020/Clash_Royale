#include "myminion3.h"
#include "yourbuilding.h"
#include "yourminions.h"
#include <QPixmap>
#include <QTimer>

Myminion3::Myminion3(QGraphicsItem *parent)
{
    QPixmap p;p.load(":/image/character3.png");
    qreal width = p.width();qreal height = p.height();
    p=p.scaled(width/5,height/5,Qt::KeepAspectRatio);
    setPixmap(p);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(timer,SIGNAL(timeout()),this,SLOT(aim_target()));
    timer->start(150);
}
void Myminion3::aim_target()
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
        setPos(x()-9,y());
    }
}
void Myminion3::fire()
{
    Myminions::fire();
}
void Myminion3::move()
{
    if(pos().x()>1600&&pos().y()>350)setPos(x(),y()-9);
    else if(pos().x()>1600&&pos().y()<350)setPos(x(),y()+9);
    else setPos(x()+9,y());
}
