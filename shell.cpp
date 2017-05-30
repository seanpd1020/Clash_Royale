#include "shell.h"
#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <qmath.h>
#include "game.h"
#include "myminion1.h"
#include "myminion2.h"
#include "myminion3.h"
#include "myminion4.h"
#include "myminion5.h"
#include "myminion6.h"
#include "myminion7.h"
#include "myminion8.h"
#include "myminion9.h"
#include "myminion10.h"
#include "yourminion1.h"
#include "yourminion2.h"
#include "yourminion3.h"
#include "yourminion4.h"
#include "yourminion5.h"
#include "yourminion6.h"
#include "yourminion7.h"
#include "yourminion8.h"
#include "yourminion9.h"
#include "yourminion10.h"
extern Game *game;

Shell::Shell(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent)
{
    QPixmap p;p.load(":/image/shell.png");
    qreal width = p.width();qreal height = p.height();
    p=p.scaled(width/10,height/10,Qt::KeepAspectRatio);
    setPixmap(p);

    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);

    s = new QMediaPlayer();
    s->setMedia(QUrl("qrc:/sound/bomb.mp3"));
    s->play();
}
void Shell::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Myminion1)||typeid(*(colliding_items[i])) == typeid(Myminion2)||
           typeid(*(colliding_items[i])) == typeid(Myminion3)||typeid(*(colliding_items[i])) == typeid(Myminion4)||
           typeid(*(colliding_items[i])) == typeid(Myminion5)||typeid(*(colliding_items[i])) == typeid(Myminion6)||
           typeid(*(colliding_items[i])) == typeid(Myminion7)||typeid(*(colliding_items[i])) == typeid(Myminion8)||
           typeid(*(colliding_items[i])) == typeid(Myminion9)||typeid(*(colliding_items[i])) == typeid(Myminion10)||
           typeid(*(colliding_items[i])) == typeid(Yourminion1)||typeid(*(colliding_items[i])) == typeid(Yourminion2)||
           typeid(*(colliding_items[i])) == typeid(Yourminion3)||typeid(*(colliding_items[i])) == typeid(Yourminion4)||
           typeid(*(colliding_items[i])) == typeid(Yourminion5)||typeid(*(colliding_items[i])) == typeid(Yourminion6)||
           typeid(*(colliding_items[i])) == typeid(Yourminion7)||typeid(*(colliding_items[i])) == typeid(Yourminion8)||
           typeid(*(colliding_items[i])) == typeid(Yourminion9)||typeid(*(colliding_items[i])) == typeid(Yourminion10))
        {
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            scene()->removeItem(this);
            delete this;

            return;
        }
    }
    int STEP_SIZE = 20;
    double theta = rotation();
    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));
    setPos(x()+dx, y()+dy);
    if (pos().y() < 0 || pos().x() < 0 || pos().y() > 1500 || pos().x() >1925)
    {
        scene()->removeItem(this);
        delete this;
    }
}

