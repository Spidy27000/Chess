#ifndef BOARD_H
#define BOARD_H
#include "Peice.h"
#include "Peices.h"
#include "Vec2.h"
#include <string>
#include <variant>

class Board {
public:
  Board(std::string fen);
  ~Board();
  Peice &operator[](const Vec2 &pos);
  void FillBoard(std::string fen);
  bool MakeMove(Vec2 start, Vec2 end);
  Peice board[8][8];

private:
};

#endif
