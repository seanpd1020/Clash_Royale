#include "minion8icon.h"
#include "game.h"
#include "yourminion8.h"

extern Game * game;

Minion8icon::Minion8icon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap p;p.load(":/image/character8(flip).png");
    qreal width = p.width();qreal height = p.height();
    p=p.scaled(width/3,height/3,Qt::KeepAspectRatio);
    setPixmap(p);
}
void Minion8icon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->ym8)
    {
        game->ym8 = new Yourminion8();
        game->setCursor();
    }
}
