#include "mymainbuilding.h"
#include <QTimer>
#include "game.h"

extern Game *game;

Mymainbuilding::Mymainbuilding(QGraphicsItem *parent)
{
    QPixmap p;p.load(":/image/mainbuilding(flip).png");
    qreal width = p.width();qreal height = p.height();
    p=p.scaled(width/1.5,height/1.5,Qt::KeepAspectRatio);
    setPixmap(p);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aim_target()));
    timer->start(3000);
}
void Mymainbuilding::fire(){
    Mybuilding::fire();
}

void Mymainbuilding::aim_target(){
    Mybuilding::aim_target();
}
