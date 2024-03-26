#include "laser.h"
#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsPixmapItem>
#include <QDebug>


laser::laser(): QObject(), QGraphicsPixmapItem(){

    setPixmap(QPixmap("C:/Users/marya/Downloads/arrow.png"));


    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}



void laser::move(){

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // move bullet up
    setPos(x(),y()-10);
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
