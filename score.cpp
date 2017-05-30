#include "score.h"
#include <QFont>
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score=0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",35));
}
int Score::getscore()
{
    return score;
}
void Score::increasescore()
{
    score=score+10;
    setPlainText(QString("Score: ") + QString::number(score));
}
void Score::decreasescore()
{
    score--;
    setPlainText(QString("Score: ") + QString::number(score));
}
