#include "minion6icon.h"
#include "game.h"
#include "yourminion6.h"

extern Game * game;

Minion6icon::Minion6icon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap p;p.load(":/image/character6(flip).png");
    qreal width = p.width();qreal height = p.height();
    p=p.scaled(width/3,height/3,Qt::KeepAspectRatio);
    setPixmap(p);
}
void Minion6icon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->ym6)
    {
        game->ym6 = new Yourminion6();
        game->setCursor();
    }
}
