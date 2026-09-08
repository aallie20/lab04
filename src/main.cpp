// src/main.cpp
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <string>

#include "constants.h"
#include "grading.h"
#include "printing.h"

int main() {
    int input{-1};

    const std::string names[]{"Ada Lovelace",      "Grace Hopper",
                              "Alan Turing",       "Katherine Johnson",
                              "Linus Torvalds",    "Bill Gates"};

    // A raw array knows its own length here, where its declaration is
    // visible. Passing it to a function discards that, which is why the
    // count travels alongside the pointer.
    const int nameCount{static_cast<int>(std::size(names))};

    const ScoreGrid scores{{{95.0, 88.5, 92.0, 78.0, 100.0},
                            {72.5, 80.0, 68.0, 91.0, 85.5},
                            {55.0, 62.5, 48.0, 70.0, 59.0},
                            {100.0, 98.0, 95.5, 99.0, 97.0},
                            {83.0, 79.5, 88.0, 84.0, 91.5},
                            {45.0, 52.0, 61.0, 38.5, 55.0}}};

    // Program loop
    while (input != 0) {
        std::cout << "\n=== GRADEBOOK ===\n"
                  << "1. Full Report\n"
                  << "2. Grade Distribution\n"
                  << "3. Assignment Averages\n"
                  << "4. Roster\n"
                  << "5. Class Average\n"
                  << "0. Quit\n"
                  << "Choice: ";

        if (std::cin >> input) {
            switch (input) {
                case 1: {
                    printHeader();

                    for (auto i{0}; i < nameCount; i++) {
                        printStudentRow(names[i], scores, i);
                    }

                    std::cout << "\t* perfect score\t! at risk\n";
                    break;
                }
                case 2: {
                    printHistogram(scores);
                    break;
                }
                case 3: {
                    printAssignmentSummary(scores);
                    break;
                }
                case 4: {
                    printRoster(names, nameCount);
                    break;
                }
                case 5: {
                    double avg{classAverage(scores)};

                    std::cout << "Class Average: " << std::setw(6)
                              << std::setprecision(2) << std::fixed << avg
                              << '\n';
                    break;
                }
                case 0: {
                    std::cout << "Goodbye!\n";
                    break;
                }
                default: {
                    std::cout << "Invalid choice, try again\n";
                }
            }
        } else {
            // Clear the failed read and discard the offending input
            std::cout << "Invalid input!\n";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return 0;
}
