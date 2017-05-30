#ifndef MINION2ICON_H
#define MINION2ICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Minion2icon: public QGraphicsPixmapItem{
public:
    Minion2icon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // MINION2ICON_H
