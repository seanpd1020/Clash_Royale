#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsLineItem>
#include <QIcon>
#include "mybuilding.h"
#include "myminions.h"
#include "shell.h"
#include "arrow.h"
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
Game::Game():QGraphicsView()
{
    canplay=false;
    scene=new QGraphicsScene(this);
    scene->setSceneRect(0,0,1925,1500);
    setScene(scene);

    setObjectName("background");
    setStyleSheet("#background{border-image:url(/home/pd2vm/Clash_Royale/grass.png);}");
    setWindowIcon(QIcon("/home/pd2vm/Clash_Royale/windowicon.jpg"));
    setWindowTitle("Clash Royale");
    setFixedSize(1925,1500);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    go=new Gameover();
    go->setPos(x(),y());
    scene->addItem(go);

    deterfirsttwominionicon();

}
void Game::startornot()
{
    if(twominion==2)
    {
        scene->removeEventFilter(description);
        delete description;
        scene->removeEventFilter(m1_bt);
        delete m1_bt;
        scene->removeEventFilter(m2_bt);
        delete m2_bt;
        scene->removeEventFilter(m3_bt);
        delete m3_bt;
        scene->removeEventFilter(m4_bt);
        delete m4_bt;
        scene->removeEventFilter(m5_bt);
        delete m5_bt;
        scene->removeEventFilter(m6_bt);
        delete m6_bt;
        scene->removeEventFilter(m7_bt);
        delete m7_bt;
        scene->removeEventFilter(m8_bt);
        delete m8_bt;
        scene->removeEventFilter(m9_bt);
        delete m9_bt;
        scene->removeEventFilter(m10_bt);
        delete m10_bt;
        scene->removeEventFilter(m1_btt);
        delete m1_btt;
        scene->removeEventFilter(m2_btt);
        delete m2_btt;
        scene->removeEventFilter(m3_btt);
        delete m3_btt;
        scene->removeEventFilter(m4_btt);
        delete m4_btt;
        scene->removeEventFilter(m5_btt);
        delete m5_btt;
        scene->removeEventFilter(m6_btt);
        delete m6_btt;
        scene->removeEventFilter(m7_btt);
        delete m7_btt;
        scene->removeEventFilter(m8_btt);
        delete m8_btt;
        scene->removeEventFilter(m9_btt);
        delete m9_btt;
        scene->removeEventFilter(m10_btt);
        delete m10_btt;

        if(card2==1)
        {
            scene->removeItem(mm1);
            delete mm1;
            m1=new Minion1icon();
            m1->setPos(x()+400,y()+700);
            scene->addItem(m1);
        }
        else if(card2==2)
        {
            scene->removeItem(mm2);
            delete mm2;
            m2=new Minion2icon();
            m2->setPos(x()+500,y()+700);
            scene->addItem(m2);
        }
        else if(card2==3)
        {
            scene->removeItem(mm3);
            delete mm3;
            m3=new Minion3icon();
            m3->setPos(x()+600,y()+700);
            scene->addItem(m3);
        }
        else if(card2==4)
        {
            scene->removeItem(mm4);
            delete mm4;
            m4=new Minion4icon();
            m4->setPos(x()+750,y()+740);
            scene->addItem(m4);
        }
        else if(card2==5)
        {
            scene->removeItem(mm5);
            delete mm5;
            m5=new Minion5icon();
            m5->setPos(x()+850,y()+700);
            scene->addItem(m5);
        }
        else if(card2==6)
        {
            scene->removeItem(mm6);
            delete mm6;
            m6=new Minion6icon();
            m6->setPos(x()+900,y()+700);
            scene->addItem(m6);
        }
        else if(card2==7)
        {
            scene->removeItem(mm7);
            delete mm7;
            m7=new Minion7icon();
            m7->setPos(x()+1000,y()+700);
            scene->addItem(m7);
        }
        else if(card2==8)
        {
            scene->removeItem(mm8);
            delete mm8;
            m8=new Minion8icon();
            m8->setPos(x()+1100,y()+700);
            scene->addItem(m8);
        }
        else if(card2==9)
        {
            scene->removeItem(mm9);
            delete mm9;
            m9=new Minion9icon();
            m9->setPos(x()+1200,y()+700);
            scene->addItem(m9);
        }
        else if(card2==10)
        {
            scene->removeItem(mm10);
            delete mm10;
            m10=new Minion10icon();
            m10->setPos(x()+1300,y()+700);
            scene->addItem(m10);
        }
        canplay=true;
        starttimer->stop();

        start();
    }
}
void Game::start()
{

    cursor=nullptr;
    building=nullptr;
    minions=nullptr;
    mana=20;

    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/backgroundbgm.mp3"));
    music->play();

    mymainbuildinghp=new Mymainbuildinghp();
    myminorbuildinghp1=new Myminorbuildinghp1();
    yourmainbuildinghp=new Yourmainbuildinghp();
    yourminorbuildinghp1=new Yourminorbuildinghp1();

    mymainbuildinghp->setPos(x()+50,y()+750);
    scene->addItem(mymainbuildinghp);
    myminorbuildinghp1->setPos(x()+50,y()+800);
    scene->addItem(myminorbuildinghp1);
    yourmainbuildinghp->setPos(x()+1500,y()+750);
    scene->addItem(yourmainbuildinghp);
    yourminorbuildinghp1->setPos(x()+1500,y()+800);
    scene->addItem(yourminorbuildinghp1);

    yourmana=new Yourmana();
    yourmana->setPos(x()+1300,y()+800);
    scene->addItem(yourmana);

    score=new Score();
    score->setPos(x()+1290,y()+750);
    scene->addItem(score);

    timer=new QTimer(this);
    enemytimer=new QTimer(this);
    manatimer=new QTimer(this);
    minionicontimer=new QTimer(this);

    mymainb=new Mymainbuilding();
    myminorb1=new Myminorbuilding();
    myminorb2=new Myminorbuilding();
    mymainb->setPos(x()+0,y()+200);
    myminorb1->setPos(x()+300,y()+0);
    myminorb2->setPos(x()+300,y()+400);
    scene->addItem(myminorb1);
    scene->addItem(myminorb2);
    scene->addItem(mymainb);

    yourmainb=new Yourmainbuilding();
    yourminorb1=new Yourminorbuilding();
    yourminorb2=new Yourminorbuilding();
    yourmainb->setPos(x()+1650,y()+200);
    yourminorb1->setPos(x()+1380,y()+0);
    yourminorb2->setPos(x()+1380,y()+400);
    scene->addItem(yourminorb1);
    scene->addItem(yourminorb2);
    scene->addItem(yourmainb);

    ym1=nullptr;
    ym2=nullptr;
    ym3=nullptr;
    ym4=nullptr;
    ym5=nullptr;
    ym6=nullptr;
    ym7=nullptr;
    ym8=nullptr;
    ym9=nullptr;
    ym10=nullptr;
    createyourminions();
    letmanaincrease();
    detergameover();

}
void Game::deterfirsttwominionicon()
{

    if(canplay==false)
    {
        scene->removeItem(go);
        delete go;

        starttimer=new QTimer();
        connect(starttimer,SIGNAL(timeout()),this,SLOT(startornot()));
        starttimer->start(50);

        card1=-1;card2=-1;
        canplay=false;
        twominion=0;

        mm1=new Minion1icon();mm2=new Minion2icon();
        mm3=new Minion3icon();mm4=new Minion4icon();
        mm5=new Minion5icon();mm6=new Minion6icon();
        mm7=new Minion7icon();mm8=new Minion8icon();
        mm9=new Minion9icon();mm10=new Minion10icon();
        mm1->setPos(x()+400,y()+400);mm2->setPos(x()+500,y()+400);
        mm3->setPos(x()+600,y()+400);mm4->setPos(x()+750,y()+400);
        mm5->setPos(x()+850,y()+400);mm6->setPos(x()+900,y()+400);
        mm7->setPos(x()+1000,y()+400);mm8->setPos(x()+1100,y()+400);
        mm9->setPos(x()+1200,y()+400);mm10->setPos(x()+1300,y()+400);
        scene->addItem(mm1);scene->addItem(mm2);
        scene->addItem(mm3);scene->addItem(mm4);
        scene->addItem(mm5);scene->addItem(mm6);
        scene->addItem(mm7);scene->addItem(mm8);
        scene->addItem(mm9);scene->addItem(mm10);

        m1=new Minion1icon();m2=new Minion2icon();
        m3=new Minion3icon();m4=new Minion4icon();
        m5=new Minion5icon();m6=new Minion6icon();
        m7=new Minion7icon();m8=new Minion8icon();
        m9=new Minion9icon();m10=new Minion10icon();
        m1->setPos(x()+400,y()+700);m2->setPos(x()+500,y()+700);
        m3->setPos(x()+600,y()+700);m4->setPos(x()+750,y()+700);
        m5->setPos(x()+850,y()+700);m6->setPos(x()+900,y()+700);
        m7->setPos(x()+1000,y()+700);m8->setPos(x()+1100,y()+700);
        m9->setPos(x()+1200,y()+700);m10->setPos(x()+1300,y()+700);
        scene->addItem(m1);scene->addItem(m2);
        scene->addItem(m3);scene->addItem(m4);
        scene->addItem(m5);scene->addItem(m6);
        scene->addItem(m7);scene->addItem(m8);
        scene->addItem(m9);scene->addItem(m10);

        m1_bt=new QPushButton;
        m1_bt->setText("No.1");
        m1_bt->setGeometry(450,650,90,50);
        connect(m1_bt,SIGNAL(clicked()),this,SLOT(setcard1to1()));
        scene->addWidget(m1_bt);
        m2_bt=new QPushButton;
        m2_bt->setText("No.2");
        m2_bt->setGeometry(550,650,90,50);
        connect(m2_bt,SIGNAL(clicked()),this,SLOT(setcard1to2()));
        scene->addWidget(m2_bt);
        m3_bt=new QPushButton;
        m3_bt->setText("No.3");
        m3_bt->setGeometry(650,650,90,50);
        connect(m3_bt,SIGNAL(clicked()),this,SLOT(setcard1to3()));
        scene->addWidget(m3_bt);
        m4_bt=new QPushButton;
        m4_bt->setText("No.4");
        m4_bt->setGeometry(750,650,90,50);
        connect(m4_bt,SIGNAL(clicked()),this,SLOT(setcard1to4()));
        scene->addWidget(m4_bt);
        m5_bt=new QPushButton;
        m5_bt->setText("No.5");
        m5_bt->setGeometry(850,650,90,50);
        connect(m5_bt,SIGNAL(clicked()),this,SLOT(setcard1to5()));
        scene->addWidget(m5_bt);
        m6_bt=new QPushButton;
        m6_bt->setText("No.6");
        m6_bt->setGeometry(950,650,90,50);
        connect(m6_bt,SIGNAL(clicked()),this,SLOT(setcard1to6()));
        scene->addWidget(m6_bt);
        m7_bt=new QPushButton;
        m7_bt->setText("No.7");
        m7_bt->setGeometry(1050,650,90,50);
        connect(m7_bt,SIGNAL(clicked()),this,SLOT(setcard1to7()));
        scene->addWidget(m7_bt);
        m8_bt=new QPushButton;
        m8_bt->setText("No.8");
        m8_bt->setGeometry(1150,650,90,50);
        connect(m8_bt,SIGNAL(clicked()),this,SLOT(setcard1to8()));
        scene->addWidget(m8_bt);
        m9_bt=new QPushButton;
        m9_bt->setText("No.9");
        m9_bt->setGeometry(1250,650,90,50);
        connect(m9_bt,SIGNAL(clicked()),this,SLOT(setcard1to9()));
        scene->addWidget(m9_bt);
        m10_bt=new QPushButton;
        m10_bt->setText("No.10");
        m10_bt->setGeometry(1350,650,90,50);
        connect(m10_bt,SIGNAL(clicked()),this,SLOT(setcard1to10()));
        scene->addWidget(m10_bt);

        m1_btt=new QPushButton;
        m1_btt->setText("No.1");
        m1_btt->setGeometry(450,350,90,50);
        connect(m1_btt,SIGNAL(clicked()),this,SLOT(setcard2to1()));
        scene->addWidget(m1_btt);
        m2_btt=new QPushButton;
        m2_btt->setText("No.2");
        m2_btt->setGeometry(550,350,90,50);
        connect(m2_btt,SIGNAL(clicked()),this,SLOT(setcard2to2()));
        scene->addWidget(m2_btt);
        m3_btt=new QPushButton;
        m3_btt->setText("No.3");
        m3_btt->setGeometry(650,350,90,50);
        connect(m3_btt,SIGNAL(clicked()),this,SLOT(setcard2to3()));
        scene->addWidget(m3_btt);
        m4_btt=new QPushButton;
        m4_btt->setText("No.4");
        m4_btt->setGeometry(750,350,90,50);
        connect(m4_btt,SIGNAL(clicked()),this,SLOT(setcard2to4()));
        scene->addWidget(m4_btt);
        m5_btt=new QPushButton;
        m5_btt->setText("No.5");
        m5_btt->setGeometry(850,350,90,50);
        connect(m5_btt,SIGNAL(clicked()),this,SLOT(setcard2to5()));
        scene->addWidget(m5_btt);
        m6_btt=new QPushButton;
        m6_btt->setText("No.6");
        m6_btt->setGeometry(950,350,90,50);
        connect(m6_btt,SIGNAL(clicked()),this,SLOT(setcard2to6()));
        scene->addWidget(m6_btt);
        m7_btt=new QPushButton;
        m7_btt->setText("No.7");
        m7_btt->setGeometry(1050,350,90,50);
        connect(m7_btt,SIGNAL(clicked()),this,SLOT(setcard2to7()));
        scene->addWidget(m7_btt);
        m8_btt=new QPushButton;
        m8_btt->setText("No.8");
        m8_btt->setGeometry(1150,350,90,50);
        connect(m8_btt,SIGNAL(clicked()),this,SLOT(setcard2to8()));
        scene->addWidget(m8_btt);
        m9_btt=new QPushButton;
        m9_btt->setText("No.9");
        m9_btt->setGeometry(1250,350,90,50);
        connect(m9_btt,SIGNAL(clicked()),this,SLOT(setcard2to9()));
        scene->addWidget(m9_btt);
        m10_btt=new QPushButton;
        m10_btt->setText("No.10");
        m10_btt->setGeometry(1350,350,90,50);
        connect(m10_btt,SIGNAL(clicked()),this,SLOT(setcard2to10()));
        scene->addWidget(m10_btt);

        description=new QLabel();
        description->setText("Choose Two Different Characters To Start The Game ^_^");
        description->setFont(QFont("times",30));
        scene->addWidget(description);
    }
}
void Game::setcard1to1()
{
    card1=1;
    if(card2==card1)return;
    twominion++;
    scene->removeItem(m2);
    delete m2;
    scene->removeItem(m3);
    delete m3;
    scene->removeItem(m4);
    delete m4;
    scene->removeItem(m5);
    delete m5;
    scene->removeItem(m6);
    delete m6;
    scene->removeItem(m7);
    delete m7;
    scene->removeItem(m8);
    delete m8;
    scene->removeItem(m9);
    delete m9;
    scene->removeItem(m10);
    delete m10;
}
void Game::setcard1to2()
{
    card1=2;
    if(card2==card1)return;
    twominion++;
    scene->removeItem(m1);
    delete m1;
    scene->removeItem(m3);
    delete m3;
    scene->removeItem(m4);
    delete m4;
    scene->removeItem(m5);
    delete m5;
    scene->removeItem(m6);
    delete m6;
    scene->removeItem(m7);
    delete m7;
    scene->removeItem(m8);
    delete m8;
    scene->removeItem(m9);
    delete m9;
    scene->removeItem(m10);
    delete m10;
}
void Game::setcard1to3()
{
    card1=3;
    if(card2==card1)return;
    twominion++;
    scene->removeItem(m2);
    delete m2;
    scene->removeItem(m1);
    delete m1;
    scene->removeItem(m4);
    delete m4;
    scene->removeItem(m5);
    delete m5;
    scene->removeItem(m6);
    delete m6;
    scene->removeItem(m7);
    delete m7;
    scene->removeItem(m8);
    delete m8;
    scene->removeItem(m9);
    delete m9;
    scene->removeItem(m10);
    delete m10;
}
void Game::setcard1to4()
{
    card1=4;
    if(card2==card1)return;
    twominion++;
    scene->removeItem(m2);
    delete m2;
    scene->removeItem(m3);
    delete m3;
    scene->removeItem(m1);
    delete m1;
    scene->removeItem(m5);
    delete m5;
    scene->removeItem(m6);
    delete m6;
    scene->removeItem(m7);
    delete m7;
    scene->removeItem(m8);
    delete m8;
    scene->removeItem(m9);
    delete m9;
    scene->removeItem(m10);
    delete m10;
}
void Game::setcard1to5()
{
    card1=5;
    if(card2==card1)return;
    twominion++;
    scene->removeItem(m2);
    delete m2;
    scene->removeItem(m3);
    delete m3;
    scene->removeItem(m4);
    delete m4;
    scene->removeItem(m1);
    delete m1;
    scene->removeItem(m6);
    delete m6;
    scene->removeItem(m7);
    delete m7;
    scene->removeItem(m8);
    delete m8;
    scene->removeItem(m9);
    delete m9;
    scene->removeItem(m10);
    delete m10;
}
void Game::setcard1to6()
{
    card1=6;
    if(card2==card1)return;
    twominion++;
    scene->removeItem(m2);
    delete m2;
    scene->removeItem(m3);
    delete m3;
    scene->removeItem(m4);
    delete m4;
    scene->removeItem(m5);
    delete m5;
    scene->removeItem(m1);
    delete m1;
    scene->removeItem(m7);
    delete m7;
    scene->removeItem(m8);
    delete m8;
    scene->removeItem(m9);
    delete m9;
    scene->removeItem(m10);
    delete m10;
}
void Game::setcard1to7()
{
    card1=7;
    if(card2==card1)return;
    twominion++;
    scene->removeItem(m2);
    delete m2;
    scene->removeItem(m3);
    delete m3;
    scene->removeItem(m4);
    delete m4;
    scene->removeItem(m5);
    delete m5;
    scene->removeItem(m6);
    delete m6;
    scene->removeItem(m1);
    delete m1;
    scene->removeItem(m8);
    delete m8;
    scene->removeItem(m9);
    delete m9;
    scene->removeItem(m10);
    delete m10;
}
void Game::setcard1to8()
{
    card1=8;
    if(card2==card1)return;
    twominion++;
    scene->removeItem(m2);
    delete m2;
    scene->removeItem(m3);
    delete m3;
    scene->removeItem(m4);
    delete m4;
    scene->removeItem(m5);
    delete m5;
    scene->removeItem(m6);
    delete m6;
    scene->removeItem(m7);
    delete m7;
    scene->removeItem(m1);
    delete m1;
    scene->removeItem(m9);
    delete m9;
    scene->removeItem(m10);
    delete m10;
}
void Game::setcard1to9()
{
    card1=9;
    if(card2==card1)return;
    twominion++;
    scene->removeItem(m2);
    delete m2;
    scene->removeItem(m3);
    delete m3;
    scene->removeItem(m4);
    delete m4;
    scene->removeItem(m5);
    delete m5;
    scene->removeItem(m6);
    delete m6;
    scene->removeItem(m7);
    delete m7;
    scene->removeItem(m8);
    delete m8;
    scene->removeItem(m1);
    delete m1;
    scene->removeItem(m10);
    delete m10;
}
void Game::setcard1to10()
{
    card1=10;
    if(card2==card1)return;
    twominion++;
    scene->removeItem(m2);
    delete m2;
    scene->removeItem(m3);
    delete m3;
    scene->removeItem(m4);
    delete m4;
    scene->removeItem(m5);
    delete m5;
    scene->removeItem(m6);
    delete m6;
    scene->removeItem(m7);
    delete m7;
    scene->removeItem(m8);
    delete m8;
    scene->removeItem(m9);
    delete m9;
    scene->removeItem(m1);
    delete m1;
}
void Game::setcard2to1()
{
    card2=1;
    if(card1==card2)return;
    twominion++;
    scene->removeItem(mm2);
    delete mm2;
    scene->removeItem(mm3);
    delete mm3;
    scene->removeItem(mm4);
    delete mm4;
    scene->removeItem(mm5);
    delete mm5;
    scene->removeItem(mm6);
    delete mm6;
    scene->removeItem(mm7);
    delete mm7;
    scene->removeItem(mm8);
    delete mm8;
    scene->removeItem(mm9);
    delete mm9;
    scene->removeItem(mm10);
    delete mm10;
}
void Game::setcard2to2()
{
    card2=2;
    if(card1==card2)return;
    twominion++;
    scene->removeItem(mm1);
    delete mm1;
    scene->removeItem(mm3);
    delete mm3;
    scene->removeItem(mm4);
    delete mm4;
    scene->removeItem(mm5);
    delete mm5;
    scene->removeItem(mm6);
    delete mm6;
    scene->removeItem(mm7);
    delete mm7;
    scene->removeItem(mm8);
    delete mm8;
    scene->removeItem(mm9);
    delete mm9;
    scene->removeItem(mm10);
    delete mm10;
}
void Game::setcard2to3()
{
    card2=3;
    if(card1==card2)return;
    twominion++;
    scene->removeItem(mm2);
    delete mm2;
    scene->removeItem(mm1);
    delete mm1;
    scene->removeItem(mm4);
    delete mm4;
    scene->removeItem(mm5);
    delete mm5;
    scene->removeItem(mm6);
    delete mm6;
    scene->removeItem(mm7);
    delete mm7;
    scene->removeItem(mm8);
    delete mm8;
    scene->removeItem(mm9);
    delete mm9;
    scene->removeItem(mm10);
    delete mm10;
}
void Game::setcard2to4()
{
    card2=4;
    if(card1==card2)return;
    twominion++;
    scene->removeItem(mm2);
    delete mm2;
    scene->removeItem(mm3);
    delete mm3;
    scene->removeItem(mm1);
    delete mm1;
    scene->removeItem(mm5);
    delete mm5;
    scene->removeItem(mm6);
    delete mm6;
    scene->removeItem(mm7);
    delete mm7;
    scene->removeItem(mm8);
    delete mm8;
    scene->removeItem(mm9);
    delete mm9;
    scene->removeItem(mm10);
    delete mm10;
}
void Game::setcard2to5()
{
    card2=5;
    if(card1==card2)return;
    twominion++;
    scene->removeItem(mm2);
    delete mm2;
    scene->removeItem(mm3);
    delete mm3;
    scene->removeItem(mm4);
    delete mm4;
    scene->removeItem(mm1);
    delete mm1;
    scene->removeItem(mm6);
    delete mm6;
    scene->removeItem(mm7);
    delete mm7;
    scene->removeItem(mm8);
    delete mm8;
    scene->removeItem(mm9);
    delete mm9;
    scene->removeItem(mm10);
    delete mm10;
}
void Game::setcard2to6()
{
    card2=6;
    if(card1==card2)return;
    twominion++;
    scene->removeItem(mm2);
    delete mm2;
    scene->removeItem(mm3);
    delete mm3;
    scene->removeItem(mm4);
    delete mm4;
    scene->removeItem(mm5);
    delete mm5;
    scene->removeItem(mm1);
    delete mm1;
    scene->removeItem(mm7);
    delete mm7;
    scene->removeItem(mm8);
    delete mm8;
    scene->removeItem(mm9);
    delete mm9;
    scene->removeItem(mm10);
    delete mm10;
}
void Game::setcard2to7()
{
    card2=7;
    if(card1==card2)return;
    twominion++;
    scene->removeItem(mm2);
    delete mm2;
    scene->removeItem(mm3);
    delete mm3;
    scene->removeItem(mm4);
    delete mm4;
    scene->removeItem(mm5);
    delete mm5;
    scene->removeItem(mm6);
    delete mm6;
    scene->removeItem(mm1);
    delete mm1;
    scene->removeItem(mm8);
    delete mm8;
    scene->removeItem(mm9);
    delete mm9;
    scene->removeItem(mm10);
    delete mm10;
}
void Game::setcard2to8()
{
    card2=8;
    if(card1==card2)return;
    twominion++;
    scene->removeItem(mm2);
    delete mm2;
    scene->removeItem(mm3);
    delete mm3;
    scene->removeItem(mm4);
    delete mm4;
    scene->removeItem(mm5);
    delete mm5;
    scene->removeItem(mm6);
    delete mm6;
    scene->removeItem(mm7);
    delete mm7;
    scene->removeItem(mm1);
    delete mm1;
    scene->removeItem(mm9);
    delete mm9;
    scene->removeItem(mm10);
    delete mm10;
}
void Game::setcard2to9()
{
    card2=9;
    if(card1==card2)return;
    twominion++;
    scene->removeItem(mm2);
    delete mm2;
    scene->removeItem(mm3);
    delete mm3;
    scene->removeItem(mm4);
    delete mm4;
    scene->removeItem(mm5);
    delete mm5;
    scene->removeItem(mm6);
    delete mm6;
    scene->removeItem(mm7);
    delete mm7;
    scene->removeItem(mm8);
    delete mm8;
    scene->removeItem(mm1);
    delete mm1;
    scene->removeItem(mm10);
    delete mm10;
}
void Game::setcard2to10()
{
    card2=10;
    if(card1==card2)return;
    twominion++;
    scene->removeItem(mm2);
    delete mm2;
    scene->removeItem(mm3);
    delete mm3;
    scene->removeItem(mm4);
    delete mm4;
    scene->removeItem(mm5);
    delete mm5;
    scene->removeItem(mm6);
    delete mm6;
    scene->removeItem(mm7);
    delete mm7;
    scene->removeItem(mm8);
    delete mm8;
    scene->removeItem(mm9);
    delete mm9;
    scene->removeItem(mm1);
    delete mm1;
}
void Game::letmanaincrease()
{
    connect(manatimer,SIGNAL(timeout()),this,SLOT(manaincrease()));
    manatimer->start(3000);
}
void Game::manaincrease()
{
    if(yourmana->getmana()<30)yourmana->increasemana();
    mana++;
    if(score->getscore()>0)score->decreasescore();
}
void Game::createyourminions()
{
    connect(enemytimer,SIGNAL(timeout()),this,SLOT(createenemy()));
    enemytimer->start(2000);
}
void Game::createenemy()
{
    qsrand(qrand());
    int r=(qrand()%10);
    r++;
    if(r==1)
    {
        Myminion1 *m1=new Myminion1();
        m1->setPos(x()+250,y()+200);
        scene->addItem(m1);
        mana=mana-2;
    }
    else if(r==2)
    {
        Myminion2 *m2=new Myminion2();
        m2->setPos(x()+200,y()+300);
        scene->addItem(m2);
        mana=mana-2;
    }
    else if(r==3)
    {
        Myminion3 *m3=new Myminion3();
        m3->setPos(x()+250,y()+400);
        scene->addItem(m3);
        mana=mana-2;
    }
    else if(r==4)
    {
        Myminion4 *m4=new Myminion4();
        m4->setPos(x()+250,y()+500);
        scene->addItem(m4);
        mana=mana-2;
    }
    else if(r==5)
    {
        Myminion5 *m5=new Myminion5();
        m5->setPos(x()+250,y()+480);
        scene->addItem(m5);
        mana=mana-2;
    }
    else if(r==6)
    {
        Myminion6 *m6=new Myminion6();
        m6->setPos(x()+250,y()+440);
        scene->addItem(m6);
        mana=mana-2;
    }
    else if(r==7)
    {
        Myminion7 *m7=new Myminion7();
        m7->setPos(x()+250,y()+210);
        scene->addItem(m7);
        mana=mana-2;
    }
    else if(r==8)
    {
        Myminion8 *m8=new Myminion8();
        m8->setPos(x()+250,y()+340);
        scene->addItem(m8);
        mana=mana-2;
    }
    else if(r==9)
    {
        Myminion9 *m9=new Myminion9();
        m9->setPos(x()+250,y()+350);
        scene->addItem(m9);
        mana=mana-2;
    }
    else if(r==10)
    {
        Myminion10 *m10=new Myminion10();
        m10->setPos(x()+250,y()+290);
        scene->addItem(m10);
        mana=mana-2;
    }
}
void Game::mousePressEvent(QMouseEvent *event)
{
    if (ym1)
    {

            if(yourmana->getmana()>0)
            {
                QList<QGraphicsItem *> items = cursor->collidingItems();
                for (size_t i = 0, n = items.size(); i < n; i++)
                {
                    if (dynamic_cast<Yourminion1*>(items[i]))
                    {
                        return;
                    }
                }
                if(event->pos().x()>900&&event->pos().y()<625)
                {
                    scene->addItem(ym1);
                    ym1->setPos(event->pos());
                    yourmana->decreasemana();
                    scene->removeItem(m1);
                    delete m1;
                    twominion--;
                    wash(1);
                    cursor = nullptr;
                    ym1 = nullptr;
                    ym2 = nullptr;
                    ym3 = nullptr;
                    ym4 = nullptr;
                    ym5 = nullptr;
                    ym6 = nullptr;
                    ym7 = nullptr;
                    ym8 = nullptr;
                    ym9 = nullptr;
                    ym10 = nullptr;
                }
                else QGraphicsView::mousePressEvent(event);
            }


    }
    else if (ym2)
    {

            if(yourmana->getmana()>0)
            {
                QList<QGraphicsItem *> items = cursor->collidingItems();
                for (size_t i = 0, n = items.size(); i < n; i++)
                {
                    if (dynamic_cast<Yourminion2*>(items[i]))
                    {
                        return;
                    }
                }
                if(event->pos().x()>900&&event->pos().y()<625)
                {
                    scene->addItem(ym2);
                    ym2->setPos(event->pos());
                    yourmana->decreasemana();
                    scene->removeItem(m2);
                    delete m2;
                    twominion--;
                    wash(2);
                    cursor = nullptr;
                    ym1 = nullptr;
                    ym2 = nullptr;
                    ym3 = nullptr;
                    ym4 = nullptr;
                    ym5 = nullptr;
                    ym6 = nullptr;
                    ym7 = nullptr;
                    ym8 = nullptr;
                    ym9 = nullptr;
                    ym10 = nullptr;
                }
                else QGraphicsView::mousePressEvent(event);
            }


    }
    else if (ym3)
    {

            if(yourmana->getmana()>0)
            {
                QList<QGraphicsItem *> items = cursor->collidingItems();
                for (size_t i = 0, n = items.size(); i < n; i++)
                {
                    if (dynamic_cast<Yourminion3*>(items[i]))
                    {
                        return;
                    }
                }
                if(event->pos().x()>900&&event->pos().y()<625)
                {
                    scene->addItem(ym3);
                    ym3->setPos(event->pos());
                    yourmana->decreasemana();
                    scene->removeItem(m3);
                    delete m3;
                    twominion--;
                    wash(3);
                    cursor = nullptr;
                    ym1 = nullptr;
                    ym2 = nullptr;
                    ym3 = nullptr;
                    ym4 = nullptr;
                    ym5 = nullptr;
                    ym6 = nullptr;
                    ym7 = nullptr;
                    ym8 = nullptr;
                    ym9 = nullptr;
                    ym10 = nullptr;
                }
                else QGraphicsView::mousePressEvent(event);
            }


    }
    else if (ym4)
    {

            if(yourmana->getmana()>0)
            {
                QList<QGraphicsItem *> items = cursor->collidingItems();
                for (size_t i = 0, n = items.size(); i < n; i++)
                {
                    if (dynamic_cast<Yourminion4*>(items[i]))
                    {
                        return;
                    }
                }
                if(event->pos().x()>900&&event->pos().y()<625)
                {
                    scene->addItem(ym4);
                    ym4->setPos(event->pos());
                    yourmana->decreasemana();
                    scene->removeItem(m4);
                    delete m4;
                    twominion--;
                    wash(4);
                    cursor = nullptr;
                    ym1 = nullptr;
                    ym2 = nullptr;
                    ym3 = nullptr;
                    ym4 = nullptr;
                    ym5 = nullptr;
                    ym6 = nullptr;
                    ym7 = nullptr;
                    ym8 = nullptr;
                    ym9 = nullptr;
                    ym10 = nullptr;
                }
                else QGraphicsView::mousePressEvent(event);
            }


    }
    else if (ym5)
    {

            if(yourmana->getmana()>0)
            {
                QList<QGraphicsItem *> items = cursor->collidingItems();
                for (size_t i = 0, n = items.size(); i < n; i++)
                {
                    if (dynamic_cast<Yourminion5*>(items[i]))
                    {
                        return;
                    }
                }
                if(event->pos().x()>900&&event->pos().y()<625)
                {
                    scene->addItem(ym5);
                    ym5->setPos(event->pos());
                    yourmana->decreasemana();
                    scene->removeItem(m5);
                    delete m5;
                    twominion--;
                    wash(5);
                    cursor = nullptr;
                    ym1 = nullptr;
                    ym2 = nullptr;
                    ym3 = nullptr;
                    ym4 = nullptr;
                    ym5 = nullptr;
                    ym6 = nullptr;
                    ym7 = nullptr;
                    ym8 = nullptr;
                    ym9 = nullptr;
                    ym10 = nullptr;
                }
                else QGraphicsView::mousePressEvent(event);
            }


    }
    else if (ym6)
    {

            if(yourmana->getmana()>0)
            {
                QList<QGraphicsItem *> items = cursor->collidingItems();
                for (size_t i = 0, n = items.size(); i < n; i++)
                {
                    if (dynamic_cast<Yourminion6*>(items[i]))
                    {
                        return;
                    }
                }
                if(event->pos().x()>900&&event->pos().y()<625)
                {
                    scene->addItem(ym6);
                    ym6->setPos(event->pos());
                    yourmana->decreasemana();
                    scene->removeItem(m6);
                    delete m6;
                    twominion--;
                    wash(6);
                    cursor = nullptr;
                    ym1 = nullptr;
                    ym2 = nullptr;
                    ym3 = nullptr;
                    ym4 = nullptr;
                    ym5 = nullptr;
                    ym6 = nullptr;
                    ym7 = nullptr;
                    ym8 = nullptr;
                    ym9 = nullptr;
                    ym10 = nullptr;
                }
                else QGraphicsView::mousePressEvent(event);
            }


    }
    else if (ym7)
    {

            if(yourmana->getmana()>0)
            {
                QList<QGraphicsItem *> items = cursor->collidingItems();
                for (size_t i = 0, n = items.size(); i < n; i++)
                {
                    if (dynamic_cast<Yourminion7*>(items[i]))
                    {
                        return;
                    }
                }
                if(event->pos().x()>900&&event->pos().y()<625)
                {
                    scene->addItem(ym7);
                    ym7->setPos(event->pos());
                    yourmana->decreasemana();
                    scene->removeItem(m7);
                    delete m7;
                    twominion--;
                    wash(7);
                    cursor = nullptr;
                    ym1 = nullptr;
                    ym2 = nullptr;
                    ym3 = nullptr;
                    ym4 = nullptr;
                    ym5 = nullptr;
                    ym6 = nullptr;
                    ym7 = nullptr;
                    ym8 = nullptr;
                    ym9 = nullptr;
                    ym10 = nullptr;
                }
                else QGraphicsView::mousePressEvent(event);
            }


    }
    else if (ym8)
    {

            if(yourmana->getmana()>0)
            {
                QList<QGraphicsItem *> items = cursor->collidingItems();
                for (size_t i = 0, n = items.size(); i < n; i++)
                {
                    if (dynamic_cast<Yourminion8*>(items[i]))
                    {
                        return;
                    }
                }
                if(event->pos().x()>900&&event->pos().y()<625)
                {
                    scene->addItem(ym8);
                    ym8->setPos(event->pos());
                    yourmana->decreasemana();
                    scene->removeItem(m8);
                    delete m8;
                    twominion--;
                    wash(8);
                    cursor = nullptr;
                    ym1 = nullptr;
                    ym2 = nullptr;
                    ym3 = nullptr;
                    ym4 = nullptr;
                    ym5 = nullptr;
                    ym6 = nullptr;
                    ym7 = nullptr;
                    ym8 = nullptr;
                    ym9 = nullptr;
                    ym10 = nullptr;
                }
                else QGraphicsView::mousePressEvent(event);
            }


    }
    else if (ym9)
    {

            if(yourmana->getmana()>0)
            {
                QList<QGraphicsItem *> items = cursor->collidingItems();
                for (size_t i = 0, n = items.size(); i < n; i++)
                {
                    if (dynamic_cast<Yourminion9*>(items[i]))
                    {
                        return;
                    }
                }
                if(event->pos().x()>900&&event->pos().y()<625)
                {
                    scene->addItem(ym9);
                    ym9->setPos(event->pos());
                    yourmana->decreasemana();
                    scene->removeItem(m9);
                    delete m9;
                    twominion--;
                    wash(9);
                    cursor = nullptr;
                    ym1 = nullptr;
                    ym2 = nullptr;
                    ym3 = nullptr;
                    ym4 = nullptr;
                    ym5 = nullptr;
                    ym6 = nullptr;
                    ym7 = nullptr;
                    ym8 = nullptr;
                    ym9 = nullptr;
                    ym10 = nullptr;
                }
                else QGraphicsView::mousePressEvent(event);
            }


    }
    else if (ym10)
    {

            if(yourmana->getmana()>0)
            {
                QList<QGraphicsItem *> items = cursor->collidingItems();
                for (size_t i = 0, n = items.size(); i < n; i++)
                {
                    if (dynamic_cast<Yourminion10*>(items[i]))
                    {
                        return;
                    }
                }
                if(event->pos().x()>900&&event->pos().y()<625)
                {
                    scene->addItem(ym10);
                    ym10->setPos(event->pos());
                    yourmana->decreasemana();
                    scene->removeItem(m10);
                    delete m10;
                    twominion--;
                    wash(10);
                    cursor = nullptr;
                    ym1 = nullptr;
                    ym2 = nullptr;
                    ym3 = nullptr;
                    ym4 = nullptr;
                    ym5 = nullptr;
                    ym6 = nullptr;
                    ym7 = nullptr;
                    ym8 = nullptr;
                    ym9 = nullptr;
                    ym10 = nullptr;
                }
                else QGraphicsView::mousePressEvent(event);
            }


    }
    else
    {
        QGraphicsView::mousePressEvent(event);
    }
    /*if (minions)
        {
            if(yourmana->getmana()>0)
            {
                QList<QGraphicsItem *> items = cursor->collidingItems();
                for (size_t i = 0, n = items.size(); i < n; i++)
                {
                    if (dynamic_cast<Yourminions*>(items[i]))
                    {
                        return;
                    }
                }
                if(event->pos().x()>900&&event->pos().y()<625)
                {
                    scene->addItem(minions);
                    minions->setPos(event->pos());
                    cursor = nullptr;
                    minions = nullptr;
                    yourmana->decreasemana();
                    //scene->removeItem(minions);
                }
                else QGraphicsView::mousePressEvent(event);
            }
        }*/
}
void Game::wash(int card)
{
    qsrand(qrand());
    int r=(qrand()%10)+1;
    while(card1==r||card2==r)r=(qrand()%10)+1;
    if(card==card1)
    {
        card1=r;
    }
    else if(card==card2)
    {
        card2=r;
    }

    if(r==1)
    {
        m1=new Minion1icon();
        m1->setPos(x()+400,y()+700);
        scene->addItem(m1);
        twominion++;
    }
    else if(r==2)
    {
        m2=new Minion2icon();
        m2->setPos(x()+500,y()+700);
        scene->addItem(m2);
        twominion++;
    }
    else if(r==3)
    {
        m3=new Minion3icon();
        m3->setPos(x()+600,y()+700);
        scene->addItem(m3);
        twominion++;
    }
    else if(r==4)
    {
        m4=new Minion4icon();
        m4->setPos(x()+750,y()+740);
        scene->addItem(m4);
        twominion++;
    }
    else if(r==5)
    {
        m5=new Minion5icon();
        m5->setPos(x()+850,y()+700);
        scene->addItem(m5);
        twominion++;
    }
    else if(r==6)
    {
        m6=new Minion6icon();
        m6->setPos(x()+900,y()+700);
        scene->addItem(m6);
        twominion++;
    }
    else if(r==7)
    {
        m7=new Minion7icon();
        m7->setPos(x()+1000,y()+700);
        scene->addItem(m7);
        twominion++;
    }
    else if(r==8)
    {
        m8=new Minion8icon();
        m8->setPos(x()+1100,y()+700);
        scene->addItem(m8);
        twominion++;
    }
    else if(r==9)
    {
        m9=new Minion9icon();
        m9->setPos(x()+1200,y()+700);
        scene->addItem(m9);
        twominion++;
    }
    else if(r==10)
    {
        m10=new Minion10icon();
        m10->setPos(x()+1300,y()+700);
        scene->addItem(m10);
        twominion++;
    }
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if (cursor)
    {
        cursor->setPos(event->pos());
    }
}
void Game::setCursor()
{
    if (cursor)
    {
        scene->removeItem(cursor);
        delete cursor;
    }
    cursor = new QGraphicsPixmapItem();
    scene->addItem(cursor);
}
void Game::gameover()
{
    if(mymainbuildinghp->gethp()==0)
    {
        timer->stop();
        enemytimer->stop();
        manatimer->stop();
        minionicontimer->stop();
        scene->clear();
        canplay=false;

        go=new Gameover();
        go->youwin();
        go->setPos(x()+550,y()+300);
        scene->addItem(go);

        music->stop();
/*        music->setMedia(QUrl("qrc:/sound/win.mp3"));
        music->play();
*/
        restart=new QPushButton();
        restart->setGeometry(400,850,100,25);
        restart->setText("Restart");
        connect(restart,SIGNAL(clicked()),this,SLOT(deterfirsttwominionicon()));
        scene->addWidget(restart);
        close=new QPushButton();
        close->setGeometry(500,850,100,25);
        close->setText("Quit");
        connect(close, SIGNAL(clicked()), this, SLOT(close()));
        scene->addWidget(close);

    }
    if(yourmainbuildinghp->gethp()==0)
    {
        timer->stop();
        enemytimer->stop();
        manatimer->stop();
        minionicontimer->stop();
        scene->clear();
        canplay=false;

        go=new Gameover();
        go->youlose();
        go->setPos(x()+550,y()+300);
        scene->addItem(go);

        music->stop();
/*        music->setMedia(QUrl("qrc:/sound/lose.mp3"));
        music->play();
*/
        restart=new QPushButton();
        restart->setGeometry(400,850,100,25);
        restart->setText("Restart");
        connect(restart,SIGNAL(clicked()),this,SLOT(deterfirsttwominionicon()));
        scene->addWidget(restart);
        close=new QPushButton();
        close->setGeometry(500,850,100,25);
        close->setText("Quit");
        connect(close, SIGNAL(clicked()), this, SLOT(close()));
        scene->addWidget(close);

    }

}
void Game::detergameover()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(gameover()));
    timer->start(1000);
}
