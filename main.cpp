#include "headers/Game.h"
#include "headers/setting.h"

int main() {

  Game game = Game(setting::screenHeight, setting::screenWidth, setting::fps);

  game.Run();
}
