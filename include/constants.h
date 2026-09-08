// include/constants.h
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <array>

constexpr int STUDENT_COUNT = 6;
constexpr int ASSIGNMENT_COUNT = 5;
constexpr int NAME_WIDTH = 14;

/**
 * @brief The grade grid: one row per student, one column per assignment.
 */
using ScoreGrid =
    std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>;

#endif
