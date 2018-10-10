#include "game.h"
#include "enemy.h"
#include "score.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QString>
#include <QBrush>
#include <QApplication>
#include <QPushButton>
#include <QtGui>
#include <QMessageBox>
#include <QFileDialog>
#include <QBrush>
#include <QPen>

Game::Game(){
    scene = new QGraphicsScene(); // create the scene
    scene->setSceneRect(0,0,600,400); // make the scene 800x600

    QPushButton *startButton = new QPushButton(tr("Start")); //Buttons zum Starten/Pausieren/Speichern/Laden des Spiels
    startButton->setFont(QFont("Times", 18, QFont::Bold));
    connect(startButton, SIGNAL(clicked()), this, SLOT(start()));

    QPushButton *stopButton = new QPushButton(tr("Stop"));
    stopButton->setFont(QFont("Times", 18, QFont::Bold));
    connect(stopButton, SIGNAL(clicked()), this, SLOT(stop()));

    QPushButton *saveButton = new QPushButton(tr("Save"));
    saveButton->setFont(QFont("Times", 18, QFont::Bold));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));

    QPushButton *loadButton = new QPushButton(tr("Load"));
    loadButton->setFont(QFont("Times", 18, QFont::Bold));
    connect(loadButton, SIGNAL(clicked()), this, SLOT(load()));

    QPen pen;

    scene->addEllipse(505,40,20,20, pen,QBrush(Qt::red)); //Lebenskreise, rot ausgefüllt
    scene->addEllipse(535,40,20,20, pen,QBrush(Qt::red));
    scene->addEllipse(565,40,20,20, pen,QBrush(Qt::red));
    scene->addWidget(startButton); //Buttons positionieren und zum Spielfeld hinzufügen
    startButton->move(120,0);
    scene->addWidget(stopButton);
    stopButton->move(200,0);
    scene->addWidget(saveButton);
    saveButton->move(280,0);
    scene->addWidget(loadButton);
    loadButton->move(360,0);

    setScene(scene); // make the newly created scene the scene to visualize
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(600,400);

    player = new Player(); // create the player
    player->setRect(0,0,40,40);
    player->setPos(270,330);
    player->setBrush(Qt::BDiagPattern);//Schraffierung des Spieler-Rechtecks
    player->setFlag(QGraphicsItem::ItemIsFocusable); // make the player focusable and set it to be the current focus
    player->setFocus();
    scene->addItem(player); // add the player to the scene

    score = new Score(); // create the score
    scene->addItem(score);
    health = new Health(); // create the health
    health->setPos(health->x()+500,health->y()+5); //rechts oben angezeigt
    scene->addItem(health);

    increment = 0;
    phase = 0;
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));

    show();
}

void Game::start(){
    timer->start(2000);
    //increment = 1;
}

void Game::stop(){
    timer->stop();
    //increment = 0;
}


void Game::save(){  //Speichern des Spielstandes
    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getSaveFileName(this, tr("Speichern als"), ".", tr("Savegame  (*.sav)"));
    if (fileName.isNull()==false)
    {
        file.setFileName(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Dateifehler"),
                tr("Folgende Datei kann nicht verwendet werden: ") + fileName,QMessageBox::Ok);
        }
       // game->serialize(file);
       // file.close();
       // return;
    }
}
void Game::serialize(QFile *file){
    QTextStream out(file);
    out << "Format" << endl;
    out << "score " << QString::number(score->getScore());
}

void Game::load(){  //Laden des Spielstandes
    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getOpenFileName(this, tr("Speichern als"), ".", tr("Savegame (*.sav)"));
    if (fileName.isNull()==false)
    {
        file.setFileName(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Dateifehler"),
                tr("Folgende Datei kann nicht geöffnet werden: ") + fileName,QMessageBox::Ok);
        }
    }
}

void Game::deserialize(QFile *file){
    QTextStream in(file);
    int lineNumber = 0;
    while (in.atEnd() == false) {
        QString line = in.readLine();
        if (lineNumber == 0) {
            if (line != QString("MeinZeichnungsFormat")) {
                QMessageBox::warning(this, tr("Formatfehler"),
                    tr("Das ist keine Zechnungsdatei!"), QMessageBox::Ok);
                return;
            }
        } else {
            if (line.startsWith(QString("score "))) {
                QStringList array = line.split(QString(" "));
                int newScore = array[1].toInt();
            }
        }
        lineNumber++;
    }
}
