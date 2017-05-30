#ifndef MINION8ICON_H
#define MINION8ICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Minion8icon: public QGraphicsPixmapItem{
public:
    Minion8icon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // MINION8ICON_H
