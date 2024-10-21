#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <qgraphicsitem.h>
#include "Enemy.h"

Bullet::Bullet() {
    // Установка изображения снаряда
    QPixmap bulletPixmap("D:/galacDeff/images/bullet.png");
    setPixmap(bulletPixmap);

    // Создание таймера для движения
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);  // движение каждые 50 миллисекунд
}

void Bullet::move() {
    // Проверка на столкновение с врагом
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        // Используем qgraphicsitem_cast для проверки, является ли объект врагом
        Enemy *enemy = qgraphicsitem_cast<Enemy *>(colliding_items[i]);
        if (enemy) {
            // Уничтожение врага и снаряда
            scene()->removeItem(enemy);
            scene()->removeItem(this);

            delete enemy;  // Удаляем объект врага
            delete this;    // Удаляем пулю
            return;
        }
    }

    // Движение снаряда вверх
    setPos(x(), y() - 10);
    if (pos().y() + pixmap().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
