#ifndef MINION9ICON_H
#define MINION9ICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Minion9icon: public QGraphicsPixmapItem{
public:
    Minion9icon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // MINION9ICON_H
