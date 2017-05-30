#ifndef MINION6ICON_H
#define MINION6ICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Minion6icon: public QGraphicsPixmapItem{
public:
    Minion6icon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // MINION6ICON_H
