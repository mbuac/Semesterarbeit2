#include "enemy.h"
#include "game.h"
#include "player.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QBrush>
#include <stdlib.h>

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){

    int random_number = rand() % 700; //set random x position
    setPos(random_number,0);
    setRect(0,0,100,50); // drew the (enemy) rect
    setBrush(Qt::lightGray);

    QTimer * timer = new QTimer(this); // make/connect a timer to move() the enemy every so often
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50); // start the timer
}

Enemy1::Enemy1(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){

    int random_number = rand() % 700;
    setPos(random_number,0);
    setRect(0,0,30,70);
    setBrush(Qt::SolidPattern);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

Enemy2::Enemy2(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){

    int random_number = rand() % 700;
    setPos(random_number,0);
    setRect(0,0,60,60);
    setBrush(Qt::darkCyan);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Enemy::move(){
    setPos(x(),y()+3); // move enemy down
    if (pos().y() > 400){ // destroy enemy when it goes out of the screen
        game->score->increase(); //increase the score wenn Avatar ausgewichen
        scene()->removeItem(this);
        delete this;
    }
	     /*remove enemy when colliding with avatar
    QList<QGraphicsItem *> colliding_items= collidingItems();
    for(int i=0, n=colliding_items.size(); i < n; ++i){
      if (typeid(*(colliding_items[i])) == typeid(player)){
			game->health->decrease(); //Health --
            scene()->removeItem(this);

            delete this; }
    }*/
}



void Enemy1::move(){
    setPos(x(),y()+5);
    if (pos().y() > 400){
        game->score->increase();
        scene()->removeItem(this);
        delete this;
    }
}

void Enemy2::move(){
    setPos(x(),y()+6); //Geschwindigkeit
    if (pos().y() > 400){
        game->score->increase();
        scene()->removeItem(this);
        delete this;
    }
}