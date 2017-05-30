#include "yourminorbuilding.h"
#include <QTimer>
#include "game.h"

extern Game *game;

Yourminorbuilding::Yourminorbuilding(QGraphicsItem *parent)
{
    QPixmap p;p.load(":/image/minorbuilding(flip).png");
    qreal width = p.width();qreal height = p.height();
    p=p.scaled(width/1.3,height/1.3,Qt::KeepAspectRatio);
    setPixmap(p);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aim_target()));
    timer->start(3500);
}
void Yourminorbuilding::fire()
{
    Yourbuilding::fire();
}
void Yourminorbuilding::aim_target()
{
    Yourbuilding::aim_target();
}
