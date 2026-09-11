#include <iostream>
#include "grading.h"

int main()
{
    ScoreGrid scores{};
    
    scores[0] = {98.0, 99.0, 100.0, 95.0, 97.0};
    
    applyCurve(scores, 5.0);
    for (double score : scores[0])
    {
        std::cout << score << ' ';
    }
    std::cout << '\n';
    return 0;
}
