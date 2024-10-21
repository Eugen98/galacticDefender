#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "Player.h"

class Game : public QGraphicsView {
    Q_OBJECT
public:
    Game(QWidget *parent = nullptr);

    void showStartScreen();  // Метод для отображения стартового экрана
    void startGame();  // Метод для запуска игры
    void keyPressEvent(QKeyEvent *event);  // Обработка нажатия клавиш

    QGraphicsScene *startScene;  // Сцена для стартового экрана
    QGraphicsScene *gameScene;  // Сцена для игры
    Player *player;  // Игрок
};

#endif // GAME_H
