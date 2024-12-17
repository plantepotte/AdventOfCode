//
// Created by aande on 17.12.2024.
//

#include "DayThree.h"

#include <iostream>
#include <regex>

namespace aoc {
    int SumProductsFromBuffer(const std::string &buffer) {
        const std::regex rgx{R"(mul\([0-9]{1,},[0-9]{1,}\))"};
        int sum{};

        for (auto matchIter = std::sregex_iterator(buffer.begin(), buffer.end(), rgx); matchIter != std::sregex_iterator(); ++matchIter) {
            const auto& match = *matchIter;
            const std::string substring = match.str();
            int product{1};

            std::regex numEx{R"([0-9]{1,})"};
            for (auto numIter = std::sregex_iterator(substring.begin(), substring.end(), numEx); numIter != std::sregex_iterator(); ++numIter) {
                product *= std::stoi(numIter->str());
            }
            sum += product;
        }

        return sum;
    }

    int SumProductsFromBuffer(const std::string& buffer, const bool bFilter) {

        if (!bFilter) {
            return SumProductsFromBuffer(buffer);
        }

        const std::regex rgx{R"(mul\([0-9]{1,},[0-9]{1,}\)|do\(\)|don't\(\))"};
        int sum{};

        bool bEnabled{true};
        for (auto matchIter = std::sregex_iterator(buffer.begin(), buffer.end(), rgx); matchIter != std::sregex_iterator(); ++matchIter) {
            const auto& match = *matchIter;
            const std::string substring = match.str();

            if (substring == "do()") {
                bEnabled = true;
                continue;
            }

            if (substring == "don't()") {
                bEnabled = false;
                continue;
            }

            if (bEnabled) {
                int product{1};

                std::regex numEx{R"([0-9]{1,})"};
                for (auto numIter = std::sregex_iterator(substring.begin(), substring.end(), numEx); numIter != std::sregex_iterator(); ++numIter) {
                    product *= std::stoi(numIter->str());
                }
                sum += product;
            }
        }

        return sum;
    }
} // aoc