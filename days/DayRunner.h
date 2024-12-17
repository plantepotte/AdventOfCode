//
// Created by aande on 15.12.2024.
//

#ifndef DAYRUNNER_H
#define DAYRUNNER_H
#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>

#include "DayOne.h"
#include "DayThree.h"
#include "DayTwo.h"

namespace aoc {
    static void day1() {
        const std::vector<int> A{3,4,2,1,3,3};
        const std::vector<int> B{4,3,5,3,9,3};

        const auto dist = CalcListDistance<int>(A, B);
        std::cout << "The lists are " << dist << " apart.\n";
    }

    static void day2() {
        const std::vector<std::vector<int>> reports = {
            {7, 6, 4, 2, 1},
            {1, 2, 7, 8, 9},
            {9, 7, 6, 2, 1},
            {1, 3, 2, 4, 5},
            {8, 6, 4, 4, 1},
            {1, 3, 6, 7, 9}
        };

        const auto [fst, snd] = CountSafeUnsafeLevels(reports);
        std::cout << "There are " << fst << " safe reports, and "
                  << snd << " unsafe reports.\n";
    }

    static void day3() {
        const std::filesystem::path filePath = std::filesystem::current_path() / std::filesystem::path{"../inputData/day3.txt"};
        std::ifstream inFile{filePath};

        if (!inFile.is_open()) {
            // print error message and return
            throw std::runtime_error("Failed to open file: " + filePath.string());
        }

        std::string input{};
        std::string line{};
        while (std::getline(inFile, line)) {
            input += line;
        }

        std::cout << "The sum of the products is: " << SumProductsFromBuffer(input) << ".\n";

        std::cout << "The filtered sum of products is: " << SumProductsFromBuffer(input, true);
    }
} // aoc

#endif //DAYRUNNER_H
