#ifndef MYMINORBUILDING_H
#define MYMINORBUILDING_H

#include "mybuilding.h"


class Myminorbuilding:public Mybuilding
{
    Q_OBJECT
public:
    Myminorbuilding(QGraphicsItem *parent=0);
    void fire();
public slots:
    void aim_target();
};

#endif // MYMINORBUILDING_H
