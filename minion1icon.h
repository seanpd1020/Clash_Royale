#ifndef MINION1ICON_H
#define MINION1ICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Minion1icon: public QGraphicsPixmapItem{
public:
    Minion1icon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // MINION1ICON_H
