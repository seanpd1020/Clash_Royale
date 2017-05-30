#include "mymainbuildinghp.h"
#include <QFont>
Mymainbuildinghp::Mymainbuildinghp(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    hp=500;
    setPlainText(QString("Maintower Health: ") + QString::number(hp));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",30));
}
int Mymainbuildinghp::gethp()
{
    return hp;
}
void Mymainbuildinghp::decreasehp()
{
    hp--;
    setPlainText(QString("Maintower Health: ") + QString::number(hp));
}
