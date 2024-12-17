//
// Created by aande on 17.12.2024.
//

#ifndef DAYTWO_H
#define DAYTWO_H
#include <algorithm>
#include <tuple>
#include <vector>

namespace aoc {
    template<typename T>
    requires std::floating_point<T> || std::integral<T>
    std::pair<int,int> CountSafeUnsafeLevels(const std::vector<std::vector<T>>& reports) {
        int countSafe{}, countUnsafe{};

        for (const auto& levels: reports) {
            bool safe{true};

            // check strictly increasing:
            safe = std::adjacent_find(
                levels.begin(), levels.end(),
                [](const T& a, const T& b) {
                    return a < b && b-a >= 1 && b-a <= 3;
                }
                ) == levels.end();

            // check strictly increasing:
            safe = std::adjacent_find(
                levels.begin(), levels.end(),
                [](const T& a, const T& b) {
                    return a > b && a-b >= 1 && a-b <= 3;
                }
                ) == levels.end();

            countSafe += safe;
            countUnsafe += !safe;
        }

        return std::pair<int, int>{countSafe, countUnsafe};
    }

} // aoc

#endif //DAYTWO_H
