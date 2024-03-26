#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "laser.h"
#include "Enemy.h"
#include <QDebug>


void player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
            setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
            setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Space){
        laser * Laser = new laser();
        Laser->setPos(x()+40,y());
        scene()->addItem(Laser);


}

}

void player::spawn(){



    Enemy * enemy = new Enemy();

    scene()->addItem(enemy);

}
