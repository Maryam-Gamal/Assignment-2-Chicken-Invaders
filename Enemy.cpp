#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QDebug>
Enemy::Enemy(): QObject(), QGraphicsPixmapItem(){

    int random_number = rand() % 700;
    setPos(random_number,0);

    setPixmap(QPixmap("C:/Users/marya/Downloads/chicken4.png"));



    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    setPos(x(),y()+5);
    if (pos().y() > 600){
        scene()->removeItem(this);
        delete this;
    }
}
