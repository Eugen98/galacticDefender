#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>

Enemy::Enemy() {
    // Установка случайной позиции
    int random_number = rand() % 700;
    setPos(random_number, 0);

    // Установка изображения врага
    setPixmap(QPixmap("D:/galacDeff/images/enemy.png"));

    // Движение врага
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(100);
}

void Enemy::move() {
    // Движение врага вниз
    setPos(x(),y()+5);

    // Удаление врага при достижении нижней границы
    if (pos().y() > 600) {
        scene()->removeItem(this);
        delete this;
    }
}
