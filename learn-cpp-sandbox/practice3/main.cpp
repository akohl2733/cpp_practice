#include <iostream>
#include "lesson_11.h"

void printInt(char) = delete;
void printInt(bool) = delete;

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
    auto f = max(13.55, 12);

    std::cout << f << "\n";

    return 0;
}