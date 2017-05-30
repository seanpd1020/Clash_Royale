#include "myminion2.h"
#include "yourbuilding.h"
#include "yourminions.h"
#include "arrow.h"
#include "game.h"
#include <QPixmap>
#include <QTimer>
extern Game *game;
Myminion2::Myminion2(QGraphicsItem *parent)
{
    QPixmap p;p.load(":/image/character2.png");
    qreal width = p.width();qreal height = p.height();
    p=p.scaled(width/5,height/5,Qt::KeepAspectRatio);
    setPixmap(p);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(timer,SIGNAL(timeout()),this,SLOT(aim_target()));
    timer->start(200);
}
void Myminion2::aim_target()
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
        setPos(x()-12,y());
    }
}
void Myminion2::fire()
{
    Arrow *arrow1=new Arrow();
    Arrow *arrow2=new Arrow();
    arrow1->setPos(x()+90,y());
    arrow2->setPos(x()+90,y());
    QLineF ln(QPointF(x(),y()),attack_destination);
    int angle = -1 * ln.angle();
    arrow1->setRotation(angle);
    arrow2->setRotation(angle);
    game->scene->addItem(arrow1);
    game->scene->addItem(arrow2);
}
void Myminion2::move()
{
    if(pos().x()>1600&&pos().y()>350)setPos(x(),y()-12);
    else if(pos().x()>1600&&pos().y()<350)setPos(x(),y()+12);
    else setPos(x()+12,y());
}
