#include "minion2icon.h"
#include "game.h"
#include "yourminion2.h"

extern Game * game;

Minion2icon::Minion2icon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap p;p.load(":/image/character2(flip).png");
    qreal width = p.width();qreal height = p.height();
    p=p.scaled(width/3,height/3,Qt::KeepAspectRatio);
    setPixmap(p);
}
void Minion2icon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->ym2)
    {
        game->ym2 = new Yourminion2();
        game->setCursor();
    }
}
