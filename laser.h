#ifndef LASER_H
#define LASER_H

#include <QGraphicsRectItem>
#include <QObject>

class laser: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    laser();

public slots:
    void move();



};

#endif // BULLET_H
