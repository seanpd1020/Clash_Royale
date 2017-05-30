#include "minion5icon.h"
#include "game.h"
#include "yourminion5.h"

extern Game * game;

Minion5icon::Minion5icon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap p;p.load(":/image/character5(flip).png");
    qreal width = p.width();qreal height = p.height();
    p=p.scaled(width/3,height/3,Qt::KeepAspectRatio);
    setPixmap(p);
}
void Minion5icon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->ym5)
    {
        game->ym5 = new Yourminion5();
        game->setCursor();
    }
}
