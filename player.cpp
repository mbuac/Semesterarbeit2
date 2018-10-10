#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QtGui>
#include "enemy.h"
#include "game.h"

extern Game * game;

Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent){
}

void Player::keyPressEvent(QKeyEvent *event){ // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 650)
        setPos(x()+10,y());
    }
}

void Player::spawn(){
    Enemy * enemy = new Enemy(); // create an enemy
    scene()->addItem(enemy);
    Enemy1 * enemy1 = new Enemy1(); // create other enemies:
    scene()->addItem(enemy1);
    Enemy2 * enemy2 = new Enemy2();
    scene()->addItem(enemy2);
}
