#include "../Utils/setting.h"
#include "Game.h"

int main() {

  Game game = Game(setting::screenHeight, setting::screenWidth, setting::fps);

  game.Run();
}
