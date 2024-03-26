#include <QApplication>
#include "player.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include "Score.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);


    QGraphicsScene * scene = new QGraphicsScene();


    QPixmap pixmap1("C:/Users/marya/Downloads/rocket2.png");
    pixmap1 = pixmap1.scaledToHeight(80);
    pixmap1 = pixmap1.scaledToWidth(80);
    player * Player = new player();
    Player->setPixmap(pixmap1);
    Player->setPos(400,500);
    scene->addItem(Player);
    Player->setFlag(QGraphicsItem::ItemIsFocusable);
    Player->setFocus();

    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    Score *SCORE = new Score();
    scene->addItem(SCORE);

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),Player,SLOT(spawn()));
    timer->start(2000);

    return a.exec();
}
