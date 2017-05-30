#include "buildminorbuilding.h"
#include "game.h"
#include "myminorbuilding.h"

extern Game *game;

Buildminorbuilding::Buildminorbuilding(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap("/home/pd2vm/Clash_Royale/minorbuilding.png"));
}
