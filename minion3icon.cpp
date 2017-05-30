#include "minion3icon.h"
#include "game.h"
#include "yourminion3.h"

extern Game * game;

Minion3icon::Minion3icon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap p;p.load(":/image/character3(flip).png");
    qreal width = p.width();qreal height = p.height();
    p=p.scaled(width/3,height/3,Qt::KeepAspectRatio);
    setPixmap(p);
}
void Minion3icon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->ym3)
    {
        game->ym3 = new Yourminion3();
        game->setCursor();
    }
}
