//
// Created by aande on 15.12.2024.
//

#ifndef DAYONE_H
#define DAYONE_H
#include <vector>
#include <algorithm>
#include <map>

namespace aoc {

    template<typename T>
    requires std::integral<T>
    T CalcListDistance(std::vector<T> A, std::vector<T> B) {
        const size_t n{std::min(A.size(), B.size())};

        std::sort(A.begin(), A.end());
        std::sort(B.begin(), B.end());

        T dist{};
        for (size_t i = 0; i < n; ++i) {
            dist += std::abs(A[i] - B[i]);
        }
        return dist;
    }

    template<typename T>
    requires std::integral<T>
    T CalculateSimilarityScore(const std::vector<T>& A, const std::vector<T>& B) {
        std::map<T, size_t> counter{};

        for (auto number: B) {
            if (!counter.contains(number)) counter[number] = 0;
            counter[number] += 1;
        }

        int sum{};
        for (auto number: A) {
            if (counter.contains(number)) {
                sum += number * counter[number];
            }
        }

        return sum;
    }

} // aoc

#endif //DAYONE_H
