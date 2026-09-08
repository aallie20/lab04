// include/printing.h
#ifndef PRINTING_H
#define PRINTING_H

#include <string>

#include "constants.h"

/**
 * @brief Prints the column header for the full grade report.
 *
 * @post Writes to standard output.
 */
void printHeader();

/**
 * @brief Prints one student's row of the full grade report.
 *
 * The row shows the padded name, each assignment score, the average,
 * the letter grade, and markers for a perfect score or at-risk status.
 *
 * @pre studentIndex is in the range [0, STUDENT_COUNT).
 * @post Neither name nor scores is modified.
 * @post Writes to standard output.
 *
 * @param[in] name          The student's full name.
 * @param[in] scores        The grade grid.
 * @param[in] studentIndex  Row of the student to print.
 */
void printStudentRow(const std::string& name, const ScoreGrid& scores,
                     int studentIndex);

/**
 * @brief Prints a bar chart of how many students earned each letter grade.
 *
 * @post The scores grid is not modified.
 * @post Writes to standard output.
 *
 * @param[in] scores  The grade grid.
 */
void printHistogram(const ScoreGrid& scores);

/**
 * @brief Prints the mean score for each assignment.
 *
 * Assignments averaging below 70 are flagged for review.
 *
 * @post The scores grid is not modified.
 * @post Writes to standard output.
 *
 * @param[in] scores  The grade grid.
 */
void printAssignmentSummary(const ScoreGrid& scores);

/**
 * @brief Prints each student's initials beside their full name.
 *
 * @pre names points to at least nameCount consecutive strings.
 * @pre nameCount is not negative.
 * @post No name is modified.
 * @post Writes to standard output.
 *
 * @param[in] names      Pointer to the first name in the roster.
 * @param[in] nameCount  How many names the roster holds.
 */
void printRoster(const std::string* names, int nameCount);

#endif
