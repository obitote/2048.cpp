#ifndef GAME_H
#define GAME_H

#include "color.hpp"
#include "gameboard.hpp"
#include "global.hpp"
#include "point2d.hpp"
#include "scores.hpp"
#include "statistics.hpp"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <random>
#include <sstream>
#include <string>
#include <vector>

enum Directions { UP, DOWN, RIGHT, LEFT };

class Game {

private:
  bool moved;
  bool win;
  bool boardFull;
  bool rexit;
  ull score;
  ull bestScore;
  ull largestTile;
  long long moveCount;
  double duration;
  GameBoard gamePlayBoard;
  RandInt randInt;
  bool stateSaved;
  bool noSave;

  enum ContinueStatus { STATUS_END_GAME = 0, STATUS_CONTINUE = 1 };
  enum KeyInputErrorStatus { STATUS_INPUT_VALID = 0, STATUS_INPUT_ERROR = 1 };
  enum { COMPETITION_GAME_BOARD_PLAY_SIZE = 4 };

  void initialiseContinueBoardArray();
  void drawBoard();
  void drawScoreBoard(std::ostream &out_stream);
  void input(KeyInputErrorStatus err = STATUS_INPUT_VALID);
  void decideMove(Directions);
  void move(point2D_t pt, point2D_t pt_offset);
  void statistics();
  void saveStats();
  void saveScore();
  void saveState();
  void playGame(ContinueStatus);
  ull setBoardSize();

public:
  Game()
      : win(false), moved(true), boardFull(false), rexit(false), score(0),
        bestScore(0), moveCount(-1), duration(0.0), largestTile(2),
        stateSaved(false), noSave(false) {}
  void startGame();
  void continueGame();
};

#endif
