// Copyright 2022 jbcumming

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#define WIN 6
#define DRAW 3
#define LOSE 0

enum shape { rock, paper, scissors };

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

int resultScore(shape opponent, shape player) {
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

int main() {
  std::string line;
  int totalScore = 0;

  std::ifstream gameStrategyFile("input.txt");
  while (std::getline(gameStrategyFile, line)) {
    shape opponent = getShape(line.at(0));
    shape player = getShape(line.at(2));

    totalScore += shapeScore(player);
    totalScore += resultScore(opponent, player);
  }
  gameStrategyFile.close();
  std::cout << totalScore << "\n";
}
