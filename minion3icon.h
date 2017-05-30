#ifndef MINION3ICON_H
#define MINION3ICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Minion3icon: public QGraphicsPixmapItem{
public:
    Minion3icon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // MINION3ICON_H
