#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

#include "Health.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);


};

#endif // GAME_H
