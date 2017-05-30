#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <QGraphicsTextItem>
class Gameover: public QGraphicsTextItem
{
public:
    Gameover(QGraphicsItem * parent=0);
    void youwin();
    void youlose();
};
#endif // GAMEOVER_H
