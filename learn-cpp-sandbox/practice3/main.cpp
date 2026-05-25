#include <iostream>
#include "lesson_11.h"
#include "lesson_f.h"

// #define CONSTEVAL(...) [] consteval { return __VA_ARGS__; }() 

// void printInt(char) = delete;
// void printInt(bool) = delete;

int main() {

    // std::cout << add(17, 89) << std::endl;


    // printInt(56);
    // printInt('a');
    // printInt(97.6);
    // printInt(true);

    // defaultArgs();
    // defArgs();

    // std::cout << printVal(89.9, 80.1);

    // int g = printMax<int>(10, 45);
    // int f = printMax(static_cast<double>(10), 10.49);
    // double f = printMax<double>(10, 10.49);
    // auto f = max(13.55, 12);
    // std::cout << f << "\n";

    // constexpr double cirumference { calculateCirc(10) };
    // std::cout << cirumference << std::endl;

    // constexpr int x { getMax(7, 8) };
    // std::cout << x << std::endl;
    // std::cout << getMax(78, 90) << " should be " << 90 << std::endl;

    // int x{5};
    // std::cout << compare(x, 9) << std::endl;
    // std::cout << compare(5, 9) << std::endl;
    // std::cout << CONSTEVAL(compare(5, 9)) << std::endl;

    constexpr int g { doSomething(5,6) };
    std::cout << g << std::endl;

    return 0;
}