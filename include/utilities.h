// include/utilities.h
#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

/**
 * @brief Converts a numeric average into a letter grade.
 *
 * @post No state outside the return value is affected.
 *
 * @param[in] average  The numeric average, normally 0.0 to 100.0.
 * @return 'A', 'B', 'C', 'D', or 'F'.
 */
[[nodiscard]] char letterGrade(double average);

/**
 * @brief Converts a letter grade into grade points.
 *
 * @post Any letter outside 'A'-'D' yields 0.0.
 *
 * @param[in] letter  The letter grade.
 * @return The grade point value, 0.0 to 4.0.
 */
[[nodiscard]] double gradePoints(char letter);

/**
 * @brief Builds the initials of a full name.
 *
 * @pre fullName contains at least a first and last name separated by a space.
 * @post fullName is not modified.
 *
 * @param[in] fullName  The name to abbreviate, such as "Ada Lovelace".
 * @return The initials with periods, such as "A. L.".
 */
[[nodiscard]] std::string initialsOf(const std::string& fullName);

/**
 * @brief Pads or truncates a name to an exact display width.
 *
 * @pre width is not negative.
 * @post fullName is not modified.
 *
 * @param[in] fullName  The name to fit.
 * @param[in] width     The exact number of characters to produce.
 * @return A string of exactly width characters.
 */
[[nodiscard]] std::string padName(const std::string& fullName, int width);

#endif
