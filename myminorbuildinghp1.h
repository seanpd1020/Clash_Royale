#ifndef MYMINORBUILDINGHP1_H
#define MYMINORBUILDINGHP1_H
#include <QGraphicsTextItem>
class Myminorbuildinghp1: public QGraphicsTextItem
{
public:
    Myminorbuildinghp1(QGraphicsItem * parent=0);
    int gethp();
    void decreasehp();
private:
    int hp;
};


#endif // MYMINORBUILDINGHP_H
