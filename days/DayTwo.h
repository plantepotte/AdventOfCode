//
// Created by aande on 17.12.2024.
//

#ifndef DAYTWO_H
#define DAYTWO_H
#include <algorithm>
#include <iostream>
#include <vector>

namespace aoc {
    template<typename T> requires std::floating_point<T> || std::integral<T>
    bool CheckIfIncreasing(const auto& begin, const auto& end) {
        return std::adjacent_find(
                   begin, end,
                   [](const T &a, const T &b) {
                       return a >= b || b - a < 1 || b - a > 3;
                   }
               ) == end;
    }

    template<typename T> requires std::floating_point<T> || std::integral<T>
    bool CheckIfDecreasing(const auto& begin, const auto& end) {
        return std::adjacent_find(
                   begin, end,
                   [](const T &a, const T &b) {
                       return a <= b || a - b < 1 || a - b > 3;
                   }
               ) == end;
    }

    template<typename T>
    requires std::floating_point<T> || std::integral<T>
    int CountSafeUnsafeLevels(const std::vector<std::vector<T>>& reports) {
        int countSafe{};

        for (const auto& levels: reports) {
            bool safe{true};

            // check strictly increasing:
            safe = CheckIfIncreasing<T>(levels.begin(), levels.end());
            if (safe) {
                countSafe += safe;
                continue;
            }

            // check strictly increasing:
            safe = CheckIfDecreasing<T>(levels.begin(), levels.end());

            countSafe += safe;
        }

        return countSafe;
    }

    template<typename T>
    requires std::floating_point<T> || std::integral<T>
    int CountSafeUnsafeLevels(const std::vector<std::vector<T>>& reports, bool bDampen) {

        if (!bDampen) {
            return CountSafeUnsafeLevels(reports);
        }

        int countSafe{};

        for (const auto& levels: reports) {
            bool safe{true};

            // check strictly increasing:
            auto unsafeIter = std::adjacent_find(
                   levels.begin(), levels.end(),
                   [](const T &a, const T &b) {
                       return a >= b || b - a < 1 || b - a > 3;
                   }
               );
            if (unsafeIter != levels.end() && unsafeIter+1 != levels.end() && unsafeIter+2 != levels.end()) {
                auto a = *unsafeIter;
                auto b = *(unsafeIter+2);

                if (a >= b || b - a < 1 || b - a > 3) {
                    safe = false;
                }
            }
            if (safe) {
                countSafe += safe;
                continue;
            }

            safe = true;
            // check strictly decreasing:
            unsafeIter = std::adjacent_find(
                   levels.begin(), levels.end(),
                   [](const T &a, const T &b) {
                       return a <= b || a - b < 1 || a - b > 3;
                   }
               );
            if (unsafeIter != levels.end() && unsafeIter+1 != levels.end() && unsafeIter+2 != levels.end()) {
                auto a = *unsafeIter;
                auto b = *(unsafeIter+2);

                if (a <= b || a - b < 1 || a - b > 3) {
                    safe = false;
                }
            }

            countSafe += safe;
        }

        return countSafe;
    }

} // aoc

#endif //DAYTWO_H
