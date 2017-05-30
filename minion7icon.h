#ifndef MINION7ICON_H
#define MINION7ICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Minion7icon: public QGraphicsPixmapItem{
public:
    Minion7icon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // MINION7ICON_H
