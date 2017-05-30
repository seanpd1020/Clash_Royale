#ifndef YOURMAINBUILDINGHP_H
#define YOURMAINBUILDINGHP_H
#include <QGraphicsTextItem>
class Yourmainbuildinghp: public QGraphicsTextItem
{
public:
    Yourmainbuildinghp(QGraphicsItem * parent=0);
    int gethp();
    void decreasehp();
private:
    int hp;
};


#endif // YOURMAINBUILDINGHP_H
