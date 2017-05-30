#ifndef YOURMAINBUILDING_H
#define YOURMAINBUILDING_H

#include "yourbuilding.h"


class Yourmainbuilding:public Yourbuilding
{
    Q_OBJECT
public:
    Yourmainbuilding(QGraphicsItem *parent=0);
    void fire();
public slots:
    void aim_target();
};

#endif // YOURMAINBUILDING_H
