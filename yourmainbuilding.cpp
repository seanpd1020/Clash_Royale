#include "yourmainbuilding.h"
#include <QTimer>
#include "game.h"

extern Game *game;

Yourmainbuilding::Yourmainbuilding(QGraphicsItem *parent)
{
    QPixmap p;p.load(":/image/mainbuilding.png");
    qreal width = p.width();qreal height = p.height();
    p=p.scaled(width/1.5,height/1.5,Qt::KeepAspectRatio);
    setPixmap(p);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aim_target()));
    timer->start(3000);
}
void Yourmainbuilding::fire(){
    Yourbuilding::fire();
}

void Yourmainbuilding::aim_target(){
    Yourbuilding::aim_target();
}
