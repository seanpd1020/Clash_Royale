#ifndef MYMAINBUILDINGHP_H
#define MYMAINBUILDINGHP_H
#include <QGraphicsTextItem>
class Mymainbuildinghp: public QGraphicsTextItem
{
public:
    Mymainbuildinghp(QGraphicsItem * parent=0);
    int gethp();
    void decreasehp();
private:
    int hp;
};

#endif // MYMAINBUILDINGHP_H
