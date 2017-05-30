#include "yourminorbuildinghp1.h"
#include "QFont"
Yourminorbuildinghp1::Yourminorbuildinghp1(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    hp=500;
    setPlainText(QString("Minortower Health: ") + QString::number(hp));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",28));
}
int Yourminorbuildinghp1::gethp()
{
    return hp;
}
void Yourminorbuildinghp1::decreasehp()
{
    hp--;
    setPlainText(QString("Minortower Health: ") + QString::number(hp));
}
