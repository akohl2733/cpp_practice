#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "lesson_4_1.h"
#include "lesson_5.h"

int main()
{
    // std::cout << returnWhatever() << std::endl;

    // getWholeName();

    // std::cout << getStrLen("This is a long ass sentence. I want to see what the output is.") << std::endl;

    // double area {0.0};
    // double perimeter {0.0};

    // getRectangeStats(5.6, 7.8, area, perimeter);

    // std::cout << "The area is: " << area << std::endl;
    // std::cout << "The perimeter is: " << perimeter << std::endl;

    // auto [a, p] = getRectangeStatsRedux(5.6, 7.8);
    // std::cout << "The area is: " << a << std::endl;
    // std::cout << "The perimeter is: " << p << std::endl;

    std::string s{ "Hello, world!" };
    std::string sv = s;

    sv = "Goodbye, world";

    std::cout << sv << std::endl;
    std::cout << s << std::endl;

    return 0;
}