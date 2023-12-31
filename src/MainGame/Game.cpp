#include "Game.h"
#include "../ChessApi/Board.h"
#include "../Utils/setting.h"
#include <iostream>

Game::Game(int height, int width, int fps) {
  FPS = fps;
  this->height = height;
  this->width = width;

  allSprites = GetAllImages();
  currState = 0;

  InitWindow(this->height, this->width, this->title);
  ImportAllImages();
  SetTargetFPS(FPS);
}

std::vector<std::string> Game::GetAllImages() {
  return {"Board", "bB", "bK", "bN", "bP", "bQ", "bR",
          "wB",    "wK", "wN", "wP", "wQ", "wR"};
}

Game::~Game() {
  UnloadAllImages();
  CloseWindow();
}
void Game::ImportAllImages() {
  for (std::string file : allSprites) {
    allTextures[file] = (LoadTexture(("Sprites/" + file + ".png").c_str()));
  }
}
void Game::UnloadAllImages() {
  for (auto &text : allTextures) {
    UnloadTexture(text.second);
  }
}

void Game::Run() {
  while (!WindowShouldClose()) {
    Update();
    BeginDrawing();
    Draw();
    EndDrawing();
  }
}
void Game::ControlGameState() {
  Vec2 pos;

  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    pos = GetMousePos();
    switch (currState) {

    case 0: {

      if (board[pos].peice->id != peices::none &&
          ((board[pos].peice->color) == peices::white)) {
        startPos = pos;
        currState = 1;
        isHighlighted = true;
      } else {
        currState = 0;
      }
      break;
    }
    case 1: {

      endPos = pos;
      if (endPos == startPos) {
        currState = 0;
        isHighlighted = false;
        break;
      } else if (board.MakeMove(startPos, endPos)) {
        currState = 2;
        isHighlighted = false;
        break;
      } else {
        currState = 1;
        break;
      }
    }
    case 2: {

      if (board[pos].peice->id != peices::none &&
          ((board[pos].peice->color == peices::black))) {
        startPos = pos;
        currState = 3;
        isHighlighted = true;
      } else {
        currState = 2;
      }
      break;
    }
    case 3: {
      endPos = pos;
      if (endPos == startPos) {
        currState = 2;
        isHighlighted = false;
        break;
      } else if (board.MakeMove(startPos, endPos)) {
        isHighlighted = false;
        currState = 0;
        break;
      } else {
        currState = 3;
        break;
      }
    }

    default:
      break;
    }
    std::cout << std::endl;
    std::cout << currState << std::endl;
    std::cout << startPos.x << "," << startPos.y << std::endl;
    std::cout << endPos.x << "," << endPos.y << std::endl;
  }
}

void Game::Update() { ControlGameState(); }

Vec2 Game::GetMousePos() {
  Vector2 mousePos = GetMousePosition();
  return {static_cast<int>(mousePos.x / 100),
          static_cast<int>(mousePos.y / 100)};
}

void Game::Draw() {
  DrawTexture(allTextures["Board"], 10, 10, WHITE);
  if (isHighlighted) {
    DrawRectangle(100 * startPos.x + 10, 100 * startPos.y + 10, 100, 100,
                  Color{244, 236, 194, 200});
  }
  DrawPeices();
  if (isHighlighted) {
    MakeHighlight();
  }
}

// 20 18 19 21 22 19 18 20
// 17 17 17 17 17 17 17 17
// 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0
// 9 9 9 9 9 9 9 9
// 12 10 11 13 14 11 10 12

void Game::DrawPeices() {
  Vec2 temp;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      std::string currpeice = "";
      temp = {j, i};
      switch (board[temp].peice->id) {
      case 9:
        currpeice = "wP";
        break;
      case 10:
        currpeice = "wN";
        break;
      case 11:
        currpeice = "wB";
        break;
      case 12:
        currpeice = "wR";
        break;
      case 13:
        currpeice = "wQ";
        break;
      case 14:
        currpeice = "wK";
        break;
      case 17:
        currpeice = "bP";
        break;
      case 18:
        currpeice = "bN";
        break;
      case 19:
        currpeice = "bB";
        break;
      case 20:
        currpeice = "bR";
        break;

      case 21:
        currpeice = "bQ";
        break;

      case 22:
        currpeice = "bK";
        break;
      }
      if (currpeice != "") {
        DrawTexture(allTextures[currpeice], 20 + (j * 100), 20 + (i * 100),
                    WHITE);
      }
    }
  }
}

void Game::MakeHighlight() {

  std::vector<Vec2> moves = board[startPos].peice->GetNormalMoves(board.board);
  for (Vec2 it : moves) {
    DrawEllipse(100 * it.x + 60, 100 * it.y + 60, 12.0f, 12.0f,
                Color{127, 127, 127, 127});
  }
}
