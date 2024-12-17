//
// Created by aande on 15.12.2024.
//

#ifndef DAYRUNNER_H
#define DAYRUNNER_H
#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>
#include <regex>

#include "DayOne.h"
#include "DayThree.h"
#include "DayTwo.h"

namespace aoc {
    static void day1() {
        const std::filesystem::path filePath = std::filesystem::current_path() / std::filesystem::path{"../inputData/day1.txt"};
        std::ifstream inFile{filePath};

        if (!inFile.is_open()) {
            // print error message and return
            std::cout << "Failed to open file" << std::endl;
            throw std::runtime_error("Failed to open file: " + filePath.string());
        }

        std::vector<int> A{};
        std::vector<int> B{};

        int x, y;
        std::string line{};
        while (inFile >> x >> y) {
            A.push_back(x);
            B.push_back(y);
        }

        const auto dist = CalcListDistance<int>(A, B);
        std::cout << "The lists are " << dist << " apart.\n";

        std::cout << "The sim-score is: " << CalculateSimilarityScore(A, B);
    }

    static void day2() {
        const std::filesystem::path filePath = std::filesystem::current_path() / std::filesystem::path{"../inputData/day2.txt"};
        std::ifstream inFile{filePath};

        if (!inFile.is_open()) {
            // print error message and return
            throw std::runtime_error("Failed to open file: " + filePath.string());
        }

        std::vector<std::vector<int>> reports{};
        std::string line{};
        while (std::getline(inFile, line)) {
            const std::regex rgx{"([0-9]{1,})"};
            reports.emplace_back();

            for (auto numIt = std::sregex_iterator(line.begin(), line.end(), rgx); numIt != std::sregex_iterator(); ++numIt) {
                reports.back().push_back(std::stoi(numIt->str()));
            }
        }

        const auto numSafe = CountSafeUnsafeLevels(reports);
        std::cout << "There are " << numSafe << " safe reports.\n";

        std::cout << "There are " << CountSafeUnsafeLevels(reports, true) << " with dampen.\n";
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
