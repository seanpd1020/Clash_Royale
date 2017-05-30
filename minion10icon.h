#ifndef MINION10ICON_H
#define MINION10ICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Minion10icon: public QGraphicsPixmapItem{
public:
    Minion10icon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // MINION10ICON_H
