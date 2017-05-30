#include "minion1icon.h"
#include "game.h"
#include "yourminion1.h"

extern Game * game;

Minion1icon::Minion1icon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap p;p.load(":/image/character1(flip).png");
    qreal width = p.width();qreal height = p.height();
    p=p.scaled(width/3,height/3,Qt::KeepAspectRatio);
    setPixmap(p);
}
void Minion1icon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->ym1)
    {
        game->ym1 = new Yourminion1();
        game->setCursor();
    }
}
