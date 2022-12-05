// Copyright 2022 jbcumming

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#define WIN 6
#define DRAW 3
#define LOSE 0

enum shape { rock, paper, scissors };
enum result { win, draw, lose };

shape getShape(char code) {
  shape codeShape;
  switch (code) {
  case 'A':
  case 'X':
    codeShape = rock;
    break;
  case 'B':
  case 'Y':
    codeShape = paper;
    break;
  case 'C':
  case 'Z':
    codeShape = scissors;
    break;
  }
  return codeShape;
}

result getResult(char code) {
  result res;
  switch (code) {
  case 'X':
    res = lose;
    break;
  case 'Y':
    res = draw;
    break;
  case 'Z':
    res = win;
    break;
  }
  return res;
}

int resultScore(result res) {
  int score = 0;
  switch (res) {
  case win:
    score = WIN;
    break;
  case draw:
    score = DRAW;
    break;
  case lose:
    score = LOSE;
    break;
  }
  return score;
}

int shapeScore(shape shape) {
  int score = 0;
  switch (shape) {
  case rock:
    score = 1;
    break;
  case paper:
    score = 2;
    break;
  case scissors:
    score = 3;
    break;
  }
  return score;
}

int matchScore(shape opponent, shape player) {
  if (opponent == player) {
    return DRAW;
  }
  int score = LOSE;
  switch (opponent) {
  case rock:
    if (player == paper) {
      score = WIN;
    }
    break;
  case paper:
    if (player == scissors) {
      score = WIN;
    }
    break;
  case scissors:
    if (player == rock) {
      score = WIN;
    }
    break;
  }
  return score;
}

shape getPlay(shape opponent, result res) {
  if (res == draw) {
    return opponent;
  }
  shape play;
  switch (opponent) {
  case rock:
    play = (res == win) ? paper : scissors;
    break;
  case paper:
    play = (res == win) ? scissors : rock;
    break;
  case scissors:
    play = (res == win) ? rock : paper;
    break;
  }
  return play;
}

int main() {
  std::string line;
  int totalScore = 0;
  int totalScorePart2 = 0;

  std::ifstream gameStrategyFile("input.txt");
  while (std::getline(gameStrategyFile, line)) {
    shape opponent = getShape(line.at(0));
    shape player = getShape(line.at(2));
    result res = getResult(line.at(2));
    shape play = getPlay(opponent, res);

    totalScore += shapeScore(player);
    totalScore += matchScore(opponent, player);

    totalScorePart2 += shapeScore(play);
    totalScorePart2 += resultScore(res);
  }
  gameStrategyFile.close();
  std::cout << totalScore << "\n";
  std::cout << totalScorePart2 << "\n";
}
