#ifndef YOURMINORBUILDINGHP1_H
#define YOURMINORBUILDINGHP1_H
#include <QGraphicsTextItem>
class Yourminorbuildinghp1: public QGraphicsTextItem
{
public:
    Yourminorbuildinghp1(QGraphicsItem * parent=0);
    int gethp();
    void decreasehp();
private:
    int hp;
};

#endif // YOURMINORBUILDINGHP_H
