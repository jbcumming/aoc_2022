// Copyright 2022 jbcumming

#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::string line;
  int highestCalories = 0;
  int currentSum = 0;

  std::ifstream calorieInputFile("input.txt");

  while (std::getline(calorieInputFile, line)) {
    if (line == "") {
      if (currentSum > highestCalories) {
        highestCalories = currentSum;
      }
      currentSum = 0;
    } else {
      currentSum += std::stoi(line);
    }
  }

  calorieInputFile.close();

  std::cout << highestCalories << "\n";
}
