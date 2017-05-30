#ifndef YOURMINORBUILDING_H
#define YOURMINORBUILDING_H

#include "yourbuilding.h"


class Yourminorbuilding:public Yourbuilding
{
    Q_OBJECT
public:
    Yourminorbuilding(QGraphicsItem *parent=0);
    void fire();
public slots:
    void aim_target();
};

#endif // YOURMINORBUILDING_H
