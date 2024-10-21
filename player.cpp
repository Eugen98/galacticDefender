#include "player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

Player::Player() {
    // Загрузка изображения для игрока
    QPixmap playerPixmap("D:/galacDeff/images/player.png");
    if (playerPixmap.isNull()) {
        qDebug() << "Failed to load player image!";
    } else {
        qDebug() << "Player image loaded successfully!";
        setPixmap(playerPixmap);  // Установка изображения
    }
}

void Player::keyPressEvent(QKeyEvent *event) {
    // Управление движением игрока
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0) // Проверка границ
            setPos(x()-10, y());
    }
    else if (event->key() == Qt::Key_Right) {
        if (pos().x() + 100 < 800)  // Проверка границ
            setPos(x()+10, y());
    }
    else if (event->key() == Qt::Key_Space) {
        // Создание снаряда
        Bullet *bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }
}

void Player::spawn() {
    // Создание врагов
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
