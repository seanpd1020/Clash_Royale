#include "yourmainbuildinghp.h"
#include "QFont"
Yourmainbuildinghp::Yourmainbuildinghp(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    hp=500;
    setPlainText(QString("Maintower Health: ") + QString::number(hp));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",30));
}
int Yourmainbuildinghp::gethp()
{
    return hp;
}
void Yourmainbuildinghp::decreasehp()
{
    hp--;
    setPlainText(QString("Maintower Health: ") + QString::number(hp));
}
