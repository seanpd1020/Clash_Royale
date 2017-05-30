#include "myminorbuilding.h"
#include <QTimer>
#include "game.h"

extern Game *game;

Myminorbuilding::Myminorbuilding(QGraphicsItem *parent)
{
    QPixmap p;p.load(":/image/minorbuilding.png");
    qreal width = p.width();qreal height = p.height();
    p=p.scaled(width/1.3,height/1.3,Qt::KeepAspectRatio);
    setPixmap(p);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aim_target()));
    timer->start(3500);
}
void Myminorbuilding::fire()
{
    Mybuilding::fire();
}
void Myminorbuilding::aim_target()
{
    Mybuilding::aim_target();
}
