// src/printing.cpp
#include "printing.h"

#include <array>
#include <iomanip>
#include <iostream>
#include <string>

#include "grading.h"
#include "utilities.h"

void printHeader() {
    std::cout << padName("STUDENT", NAME_WIDTH);

    for (auto i{0}; i < ASSIGNMENT_COUNT; i++) {
        std::cout << std::setw(5) << "A" << i;
    }

    std::cout << std::setw(8) << "AVG" << std::setw(6) << "GRADE" << '\n';

    for (auto i{0}; i < 60; i++) {
        std::cout << '-';
    }

    std::cout << '\n';
}

void printStudentRow(const std::string& name, const ScoreGrid& scores,
                     int studentIndex) {
    std::cout << padName(name, NAME_WIDTH);

    for (auto i{0}; i < ASSIGNMENT_COUNT; i++) {
        std::cout << std::setw(6) << std::setprecision(1) << std::fixed
                  << scores[studentIndex][i];
    }

    double avg{studentAverage(scores, studentIndex)};

    std::cout << std::setw(8) << std::setprecision(2) << std::fixed << avg
              << " \t" << letterGrade(avg);

    if (hasPerfectScore(scores, studentIndex)) {
        std::cout << "  *";
    }

    if (isAtRisk(scores, studentIndex)) {
        std::cout << "  !";
    }

    std::cout << '\n';
}

void printHistogram(const ScoreGrid& scores) {
    std::array<char, 5> letters{{'A', 'B', 'C', 'D', 'F'}};

    std::cout << "\nGRADE DISTRIBUTION\n";

    for (auto letter : letters) {
        auto count{countGrade(scores, letter)};

        std::cout << letter << " | ";

        for (auto i{0}; i < count; i++) {
            std::cout << '#';
        }

        std::cout << "\t\t(" << count << ")\n";
    }
}

void printAssignmentSummary(const ScoreGrid& scores) {
    std::cout << "\nASSIGNMENT AVERAGES\n";

    for (auto i{0}; i < ASSIGNMENT_COUNT; i++) {
        auto avg{assignmentAverage(scores, i)};

        std::cout << "  A" << i + 1 << ": " << std::setw(6)
                  << std::setprecision(2) << std::fixed << avg;

        if (avg < 70.0) {
            std::cout << "\t<-- review this assignment";
        }

        std::cout << '\n';
    }
}

void printRoster(const std::string* names, int nameCount) {
    std::cout << "\nROSTER\n";

    // names is a pointer to the first element; it carries no size of its
    // own, so nameCount is how far we are permitted to walk
    for (auto i{0}; i < nameCount; i++) {
        std::cout << initialsOf(names[i]) << '\t' << names[i] << '\n';
    }
}
