#include "yourmana.h"
#include <QFont>
Yourmana::Yourmana(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    m=30;
    setPlainText(QString("Mana: ") + QString::number(m));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",30));
}
int Yourmana::getmana()
{
    return m;
}
void Yourmana::increasemana()
{
    m++;
    setPlainText(QString("Mana: ") + QString::number(m));
}
void Yourmana::decreasemana()
{
    m--;
    setPlainText(QString("Mana: ") + QString::number(m));
}
