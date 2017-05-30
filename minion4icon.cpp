#include "minion4icon.h"
#include "game.h"
#include "yourminion4.h"

extern Game * game;

Minion4icon::Minion4icon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap p;p.load(":/image/character4(flip).png");
    qreal width = p.width();qreal height = p.height();
    p=p.scaled(width/3,height/3,Qt::KeepAspectRatio);
    setPixmap(p);
}
void Minion4icon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->ym4)
    {
        game->ym4= new Yourminion4();
        game->setCursor();
    }
}
