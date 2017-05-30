#ifndef GAME_H
#define GAME_H
#include <QMediaPlayer>
#include "gameover.h"
#include "score.h"
#include "yourmana.h";
#include "mybuilding.h"
#include "yourminions.h"
#include "mymainbuildinghp.h"
#include "myminorbuildinghp1.h"
#include "yourmainbuildinghp.h"
#include "yourminorbuildinghp1.h"
#include "minion1icon.h"
#include "minion2icon.h"
#include "minion3icon.h"
#include "minion4icon.h"
#include "minion5icon.h"
#include "minion6icon.h"
#include "minion7icon.h"
#include "minion8icon.h"
#include "minion9icon.h"
#include "minion10icon.h"
#include "mymainbuilding.h"
#include "myminorbuilding.h"
#include "yourmainbuilding.h"
#include "yourminorbuilding.h"
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
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QLabel>
class Game:public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    void setCursor();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void createyourminions();
    void letmanaincrease();
    void detergameover();

    void start();
    void wash(int card);

    Gameover *go;
    QLabel *description;
    QMediaPlayer *music;
    Yourmana *yourmana;
    Score *score;
    QGraphicsScene *scene;
    QGraphicsPixmapItem * cursor;
    QTimer *timer;
    QTimer *starttimer;
    QTimer *enemytimer;
    QTimer *manatimer;
    QTimer *minionicontimer;
    Minion1icon * m1,* mm1;
    Minion2icon * m2,* mm2;
    Minion3icon * m3,* mm3;
    Minion4icon * m4,* mm4;
    Minion5icon * m5,* mm5;
    Minion6icon * m6,* mm6;
    Minion7icon * m7,* mm7;
    Minion8icon * m8,* mm8;
    Minion9icon * m9,* mm9;
    Minion10icon * m10,* mm10;
    Mymainbuilding *mymainb;
    Myminorbuilding *myminorb1;
    Myminorbuilding *myminorb2;
    Yourmainbuilding *yourmainb;
    Yourminorbuilding *yourminorb1;
    Yourminorbuilding *yourminorb2;
    Mymainbuildinghp *mymainbuildinghp;
    Myminorbuildinghp1 *myminorbuildinghp1;
    Yourmainbuildinghp *yourmainbuildinghp;
    Yourminorbuildinghp1 *yourminorbuildinghp1;
    Mybuilding *building;
    Yourminion1 *ym1;
    Yourminion2 *ym2;
    Yourminion3 *ym3;
    Yourminion4 *ym4;
    Yourminion5 *ym5;
    Yourminion6 *ym6;
    Yourminion7 *ym7;
    Yourminion8 *ym8;
    Yourminion9 *ym9;
    Yourminion10 *ym10;
    Yourminions *minions;
    QList<QPointF> pointsToFollow;
    QPushButton *m1_bt,*m1_btt,*m2_bt,*m2_btt,*m3_bt,*m3_btt,*m4_bt,*m4_btt,*m5_bt,*m5_btt;
    QPushButton *m6_bt,*m6_btt,*m7_bt,*m7_btt,*m8_bt,*m8_btt,*m9_bt,*m9_btt,*m10_bt,*m10_btt;
    QPushButton *close,*restart;
public slots:
    void deterfirsttwominionicon();
    void createenemy();
    void manaincrease();
    void gameover();
    void startornot();
    void setcard1to1();
    void setcard1to2();
    void setcard1to3();
    void setcard1to4();
    void setcard1to5();
    void setcard1to6();
    void setcard1to7();
    void setcard1to8();
    void setcard1to9();
    void setcard1to10();
    void setcard2to1();
    void setcard2to2();
    void setcard2to3();
    void setcard2to4();
    void setcard2to5();
    void setcard2to6();
    void setcard2to7();
    void setcard2to8();
    void setcard2to9();
    void setcard2to10();
private:
    int mana;
    int twominion;
    int card1;
    int card2;
    bool canplay;
};

#endif // GAME_H
