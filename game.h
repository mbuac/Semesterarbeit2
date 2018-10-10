#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>

#include "player.h"
#include "score.h"
#include "health.h"
#include "enemy.h"

#include <QFile>
#include <vector>
using namespace std;
#include <QWidget>
#include <QTimer>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(); //(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    Enemy * enemy;
    Game * game;

    void serialize(QFile *file);
    void deserialize(QFile *file);
private:
    QTimer * timer;
    int increment;
    int phase;
private slots:
    void start();
    void stop();
    void save();
    void load();
};

#endif // GAME_H
