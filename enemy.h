#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
public slots:
    void move();
};

class Enemy1: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Enemy1(QGraphicsItem * parent=0);
public slots:
    void move();
};

class Enemy2: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Enemy2(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // ENEMY_H
