#include "Peice.h"

mPeice::mPeice(Vec2 pos, int color, int peiceId) {

  this->pos = pos;
  this->id = peiceId | color;
  this->color = color;

  direction["north"] = {0, -1};
  direction["south"] = {0, 1};
  direction["east"] = {1, 0};
  direction["west"] = {-1, 0};
  direction["north-west"] = direction["north"] + direction["west"];
  direction["north-east"] = direction["north"] + direction["east"];
  direction["south-west"] = direction["south"] + direction["west"];
  direction["south-east"] = direction["south"] + direction["east"];
}
std::vector<Vec2> mPeice::GetMoves(std::vector<std::string> directions,
                                   int color, Peice currBoard[][8]) {
  std::vector<Vec2> validMoves = {};
  std::vector<Vec2> temp;

  for (std::string it : directions) {
    temp = GetMoveInDirection(direction[it], color, currBoard);
    validMoves.insert(validMoves.end(), temp.begin(), temp.end());
  }

  return validMoves;
}
std::vector<Vec2> mPeice::GetMoves(std::vector<Vec2> directions, int color,
                                   Peice currBoard[][8]) {
  std::vector<Vec2> validMoves = {};
  Vec2 temp = this->pos;

  for (Vec2 it : directions) {
    temp += it;
    if ((temp.x <= 7) && (temp.x >= 0) && (temp.y <= 7) && (temp.y >= 0) &&
        currBoard[temp.x][temp.y].peice->color != this->color) {
      validMoves.push_back(temp);
    }
    temp = this->pos;
  }

  return validMoves;
}

std::vector<Vec2> mPeice::GetMoveInDirection(Vec2 dir, int color,
                                             Peice board[][8]) {
  std::vector<Vec2> validMove = {};
  Vec2 tempPos = this->pos + dir;
  while ((tempPos.x <= 7) && (tempPos.x >= 0) && (tempPos.y <= 7) &&
         (tempPos.y >= 0)) {
    if (board[tempPos.x][tempPos.y].peice->color == this->color) {
      break;
    } else if (board[tempPos.x][tempPos.y].peice->color == 0) {
      validMove.push_back(tempPos);
      tempPos += dir;
      continue;
    } else if (board[tempPos.x][tempPos.y].peice->color != 0) {
      validMove.push_back(tempPos);
      break;
    }
  }
  return validMove;
}

void mPeice::SetPos(Vec2 pos) { this->pos = pos; }
