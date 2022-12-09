// Copyright 2022 jbcumming

#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex> // NOLINT [build/c++11]
#include <vector>

int main() {
  std::regex rgx("(\\d+)-(\\d+),(\\d+)-(\\d+)");
  std::string line;
  int totalOverlaps = 0;
  int totalOverlapsPart2 = 0;

  std::ifstream sectionAssignmentFile("input.txt");
  while (std::getline(sectionAssignmentFile, line)) {
    std::smatch matches;
    if (std::regex_search(line, matches, rgx)) {
      int start1 = stoi(matches[1]);
      int end1 = stoi(matches[2]);
      int start2 = stoi(matches[3]);
      int end2 = stoi(matches[4]);

      int length1 = end1 - start1;
      int length2 = end2 - start2;

      if ((length1 == length2) && (start1 == start2)) {
        totalOverlaps++;
      } else if (length1 < length2) {
        if ((start1 >= start2) && (end1 <= end2)) {
          totalOverlaps++;
        }
      } else if (length1 > length2) {
        if ((start2 >= start1) && (end2 <= end1)) {
          totalOverlaps++;
        }
      }

      if (start1 <= start2) {
        if (end1 >= start2) {
          totalOverlapsPart2++;
        }
      } else {
        if (end2 >= start1) {
          totalOverlapsPart2++;
        }
      }
    }
  }
  sectionAssignmentFile.close();
  std::cout << totalOverlaps << "\n";
  std::cout << totalOverlapsPart2 << "\n";
}
