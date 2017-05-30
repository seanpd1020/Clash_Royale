#ifndef MINION4ICON_H
#define MINION4ICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Minion4icon: public QGraphicsPixmapItem{
public:
    Minion4icon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // MINION4ICON_H
