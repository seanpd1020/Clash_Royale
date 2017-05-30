#ifndef MYMAINBUILDING_H
#define MYMAINBUILDING_H

#include "mybuilding.h"


class Mymainbuilding:public Mybuilding
{
    Q_OBJECT
public:
    Mymainbuilding(QGraphicsItem *parent=0);
    void fire();
public slots:
    void aim_target();  
};

#endif // MYMAINBUILDING_H
