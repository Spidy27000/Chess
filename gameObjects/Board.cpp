#include "../headers/Board.h"
#include "../headers/Vec2.h"
#include "../headers/setting.h"

bool Board::MakeMove(Vec2 start, Vec2 end) {

  std::vector<Vec2> validMove =
      board[start.x][start.y].peice->GetNormalMoves(board);
  bool isValidMove = false;
  for (Vec2 it : validMove) {

    if (it == end) {
      isValidMove = true;
    }
  }
  if (isValidMove) {
    board[end.x][end.y] = board[start.x][start.y];
    board[end.x][end.y].peice->SetPos(end);
    board[start.x][start.y].peice = new NonePeice(start);
    board[end.x][end.y].peice->hasMoved = true;

    return true;
  }

  return false;
}

Peice &Board::operator[](const Vec2 &pos) { return board[pos.x][pos.y]; }
void Board::FillBoard(std::string fen) {
  int row = 0, col = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      board[j][i].peice = new NonePeice({i, j});
    }
  }

  for (const char sy : fen) {
    if (sy == '/') {
      row++;
      col = 0;
      continue;

    } else if (sy >= '1' && sy <= '8') {
      col = (int)sy - 48;
      continue;
    } else {
      int color = 0;
      if (sy >= 'a' && sy <= 'z') {
        color = peices::black;
      } else if (sy >= 'A' && sy <= 'Z') {
        color = peices::white;
      }
      switch (tolower(sy)) {
      case 'b':
        board[col][row].peice = new Bishop({col, row}, color);
        break;
      case 'k':
        board[col][row].peice = new King({col, row}, color);
        break;
      case 'n':
        board[col][row].peice = new Knight({col, row}, color);
        break;
      case 'p':
        board[col][row].peice = new Pawn({col, row}, color);
        break;
      case 'q':
        board[col][row].peice = new Qween({col, row}, color);
        break;
      case 'r':
        board[col][row].peice = new Rook({col, row}, color);
        break;
      }
      col++;
    }
  }
}
Board::Board(std::string fen) { FillBoard(fen); }

Board::~Board() {
  int i, j;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      delete board[i][j].peice;
    }
  }
}
