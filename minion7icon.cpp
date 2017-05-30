#include "minion7icon.h"
#include "game.h"
#include "yourminion7.h"

extern Game * game;

Minion7icon::Minion7icon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap p;p.load(":/image/character7(flip).png");
    qreal width = p.width();qreal height = p.height();
    p=p.scaled(width/3,height/3,Qt::KeepAspectRatio);
    setPixmap(p);
}
void Minion7icon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->ym7)
    {
        game->ym7 = new Yourminion7();
        game->setCursor();
    }
}
