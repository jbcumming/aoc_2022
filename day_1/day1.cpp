// Copyright 2022 jbcumming

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::string line;
  int currentSum = 0;
  std::vector<int> calorieTotals;

  std::ifstream calorieInputFile("input.txt");
  while (std::getline(calorieInputFile, line)) {
    if (line == "") {
      calorieTotals.push_back(currentSum);
      currentSum = 0;
    } else {
      currentSum += std::stoi(line);
    }
  }
  calorieInputFile.close();

  std::sort(calorieTotals.begin(), calorieTotals.end(), std::greater<int>());
  size_t topX = 3;
  int total = 0;

  for (size_t i = 0; i < topX; ++i) {
    total += calorieTotals.at(i);
  }
  std::cout << total << "\n";
}
