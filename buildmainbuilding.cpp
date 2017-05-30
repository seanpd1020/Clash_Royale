#include "buildmainbuilding.h"
#include "game.h"
#include "mymainbuilding.h"

extern Game *game;

Buildmainbuilding::Buildmainbuilding(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap("/home/pd2vm/Clash_Royale/mainbuilding1.png"));
