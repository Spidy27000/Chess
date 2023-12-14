#pragma once

#include "Board.h"
#include "Vec2.h"
#include "raylib.h"
#include <string>
#include <unordered_map>
#include <vector>

class Game {
public:
  Game(int height, int width, int fps);
  ~Game();
  void Run();

private:
  int height, width, FPS;
  const char *title = "Chess";

  void Update();
  void ControlGameState();
  Vec2 GetMousePos();

  void Draw();

  Texture2D boardImage;
  std::vector<std::string> allSprites;
  std::unordered_map<std::string, Texture2D> allTextures;
  std::vector<std::string> GetAllImages();
  void ImportAllImages();
  void UnloadAllImages();
  void MakeHighlight();

  Board board = Board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
  void DrawPeices();

  int currState;
  Vec2 startPos, endPos;
  bool isHighlighted = false;
};
