#ifndef MINION5ICON_H
#define MINION5ICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Minion5icon: public QGraphicsPixmapItem{
public:
    Minion5icon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // MINION5ICON_H
