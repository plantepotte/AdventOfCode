//
// Created by aande on 15.12.2024.
//

#ifndef DAYONE_H
#define DAYONE_H
#include <vector>
#include <algorithm>

namespace aoc {

    template<typename T>
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

} // aoc

#endif //DAYONE_H
