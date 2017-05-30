#include "minion10icon.h"
#include "game.h"
#include "yourminion10.h"

extern Game * game;

Minion10icon::Minion10icon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap p;p.load(":/image/character10(flip).png");
    qreal width = p.width();qreal height = p.height();
    p=p.scaled(width/3,height/3,Qt::KeepAspectRatio);
    setPixmap(p);
}
void Minion10icon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->ym10)
    {
        game->ym10 = new Yourminion10();
        game->setCursor();
    }
}
