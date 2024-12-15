//
// Created by aande on 15.12.2024.
//

#ifndef DAYRUNNER_H
#define DAYRUNNER_H
#include <iostream>
#include <vector>

#include "DayOne.h"

namespace aoc {
    static void day1() {
        const std::vector<int> A{3,4,2,1,3,3};
        const std::vector<int> B{4,3,5,3,9,3};

        const auto dist = CalcListDistance<int>(A, B);
        std::cout << "The lists are " << dist << " apart.\n";
    }
} // aoc

#endif //DAYRUNNER_H
