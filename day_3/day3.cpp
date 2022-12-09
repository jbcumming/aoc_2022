// Copyright 2022 jbcumming

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#define LOWERCASE_A 97
#define LOWERCASE_Z 122
#define UPPERCASE_A 65
#define UPPERCASE_Z 90

char findDupe(std::string strA, std::string strB) {
  for (char &c : strA) {
    if (strB.find(c) != std::string::npos) {
      return c;
    }
  }
  return ' ';
}

char findTripleDupe(std::string strA, std::string strB, std::string strC) {
  for (char &c : strA) {
    if (strB.find(c) != std::string::npos) {
      if (strC.find(c) != std::string::npos) {
        return c;
      }
    }
  }
  return ' ';
}

int itemPriority(char item) {
  int ascii_code = static_cast<int>(item);
  return (ascii_code >= LOWERCASE_A && ascii_code <= LOWERCASE_Z)
             ? ascii_code - 96
             : ascii_code - 38;
}

int main() {
  std::string line;
  int totalPriority = 0;
  int totalPriorityPart2 = 0;
  std::vector<std::string> loadedRucksacks(3, "");
  int index = 0;

  std::ifstream rucksackContentsFile("input.txt");
  while (std::getline(rucksackContentsFile, line)) {
    int midPoint = line.length() / 2;
    std::string rucksackA = line.substr(0, midPoint);
    std::string rucksackB = line.substr(midPoint);

    char dupeItem = findDupe(rucksackA, rucksackB);
    totalPriority += itemPriority(dupeItem);

    loadedRucksacks.at(index % 3) = line;
    if (index % 3 == 2) {
      char tripleDupeItem = findTripleDupe(
          loadedRucksacks.at(0), loadedRucksacks.at(1), loadedRucksacks.at(2));
      totalPriorityPart2 += itemPriority(tripleDupeItem);
    }
    index++;
  }
  rucksackContentsFile.close();
  std::cout << totalPriority << "\n";
  std::cout << totalPriorityPart2 << "\n";
}
