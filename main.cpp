#include <QApplication>
#include "Game.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // new object Game
    Game *game = new Game();
    game->show();  // Вызов метода show(), который отобразит окно

    return a.exec();
}
