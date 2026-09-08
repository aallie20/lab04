// src/utilities.cpp
#include "utilities.h"

#include <string>

char letterGrade(double average) {
    if (average >= 90.0) {
        return 'A';
    } else if (average >= 80.0) {
        return 'B';
    } else if (average >= 70.0) {
        return 'C';
    } else if (average >= 60.0) {
        return 'D';
    } else {
        return 'F';
    }
}

double gradePoints(char letter) {
    switch (letter) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        default:  return 0.0;
    }
}

std::string initialsOf(const std::string& fullName) {
    std::string result{};

    result += fullName[0];
    result += ". ";

    auto index = fullName.find(' ');
    result += fullName[index + 1];
    result += '.';

    return result;
}

std::string padName(const std::string& fullName, int width) {
    std::string padded{fullName};
    padded.resize(static_cast<std::size_t>(width), ' ');
    return padded;
}
