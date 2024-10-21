#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include <QPixmap>
#include <QDebug>

Game::Game(QWidget *parent) : QGraphicsView(parent) {
    // Создаем стартовую сцену
    startScene = new QGraphicsScene(this);
    setScene(startScene);
    setFixedSize(800, 600);
    startScene->setSceneRect(0, 0, 800, 600);

    showStartScreen();  // Отображаем стартовый экран
}

// Метод для отображения стартового экрана
void Game::showStartScreen() {
    // Установка фонового изображения для стартовой сцены
    QPixmap background(":/images/start_background.png");  // Путь к изображению в ресурсах
    startScene->setBackgroundBrush(background);  // Устанавливаем изображение как фон

    // Создание текста "Galactic Defender"
    QGraphicsTextItem *titleText = new QGraphicsTextItem("Galactic Defender");
    QFont titleFont("Arial", 36);
    titleText->setFont(titleFont);
    titleText->setDefaultTextColor(Qt::white);  // Цвет текста
    titleText->setPos(200, 250);  // Положение текста
    startScene->addItem(titleText);

    // Инструкция "Press Enter to Start"
    QGraphicsTextItem *instructionText = new QGraphicsTextItem("Press Enter to Start");
    QFont instructionFont("Arial", 18);
    instructionText->setFont(instructionFont);
    instructionText->setDefaultTextColor(Qt::white);  // Цвет текста
    instructionText->setPos(250, 350);  // Положение текста
    startScene->addItem(instructionText);
}

// Метод для запуска игры
void Game::startGame() {
    // Создаем игровую сцену
    gameScene = new QGraphicsScene(this);
    setScene(gameScene);
    gameScene->setSceneRect(0, 0, 800, 600);

    // Создаем игрока и добавляем его на сцену
    player = new Player();
    player->setPos(400, 500);
    gameScene->addItem(player);

    // Пример добавления врага
    Enemy *enemy = new Enemy();
    enemy->setPos(100, 100);
    gameScene->addItem(enemy);
}

// Обработка нажатия клавиш
void Game::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        qDebug() << "Enter pressed";
        startGame();  // Начинаем игру после нажатия Enter
    }
}
