#include "minion9icon.h"
#include "game.h"
#include "yourminion9.h"

extern Game * game;

Minion9icon::Minion9icon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap p;p.load(":/image/character9(flip).png");
    qreal width = p.width();qreal height = p.height();
    p=p.scaled(width/3,height/3,Qt::KeepAspectRatio);
    setPixmap(p);
}
void Minion9icon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->ym9)
    {
        game->ym9 = new Yourminion9();
        game->setCursor();
    }
}
