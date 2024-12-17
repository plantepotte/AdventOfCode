#include <iostream>
#include "days/DayRunner.h"

int main() {
    int day;
    std::cout << "Enter the day to run:\t";
    std::cin >> day;
    std::cout << "\n";

    switch (day) {
        case 1:
            aoc::day1();
            break;
        case 2:
            aoc::day2();
            break;
        case 3:
            aoc::day3();
            break;
        default:
            std::cout << "Invalid day." << "\n";
    }

    return 0;
}
