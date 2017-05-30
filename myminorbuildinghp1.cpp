#include "myminorbuildinghp1.h"
#include "QFont"
Myminorbuildinghp1::Myminorbuildinghp1(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    hp=500;
    setPlainText(QString("Minortower Health: ") + QString::number(hp));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",28));
}
int Myminorbuildinghp1::gethp()
{
    return hp;
}
void Myminorbuildinghp1::decreasehp()
{
    hp--;
    setPlainText(QString("Minortower Health: ") + QString::number(hp));
}
