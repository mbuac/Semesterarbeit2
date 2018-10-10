#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    score = 0; // initialize the score to 0
    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(){
    score++;
    update();
}

int Score::getScore(){
    return score;
}
void Score::update(){
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

void Score::setScore(int newScore){
    score = newScore;
}
