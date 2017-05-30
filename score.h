#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
class Score: public QGraphicsTextItem
{
public:
    Score(QGraphicsItem * parent=0);
    int getscore();
    void increasescore();
    void decreasescore();
private:
    int score;
};
#endif // SCORE_H
