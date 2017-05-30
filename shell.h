#ifndef SHELL_H
#define SHELL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
class Shell:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Shell(QGraphicsItem *parent=0);
public slots:
    void move();
private:
    QMediaPlayer *s;
};

#endif // SHELL_H
