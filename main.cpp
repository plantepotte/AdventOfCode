#include <iostream>
#include "days/DayRunner.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
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

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.