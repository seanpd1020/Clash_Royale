#ifndef YOURMANA_H
#define YOURMANA_H
#include <QGraphicsTextItem>
class Yourmana: public QGraphicsTextItem
{
public:
    Yourmana(QGraphicsItem * parent=0);
    int getmana();
    void increasemana();
    void decreasemana();
private:
    int m;
};

#endif // YOURMANA_H
