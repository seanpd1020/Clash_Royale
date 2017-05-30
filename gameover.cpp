#include "gameover.h"
#include "game.h"
#include <QFont>
extern Game *game;
Gameover::Gameover(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    setPlainText(QString("test~~"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",100));
}
void Gameover::youwin()
{
    setPlainText(QString("You Win !!!\nYour Score: ")+QString::number(game->score->getscore()));
}
void Gameover::youlose()
{
    setPlainText(QString("You Lose !!!"));
}
