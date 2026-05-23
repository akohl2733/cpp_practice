#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>
#include "lesson_4_1.h"
#include "lesson_5.h"
#include "lesson_6.h"
#include "lesson_7.h"
#include "constants.h"

// need forward declaration - externally linked from a.cpp
// void sayHi();

// extern int globe_var_y;
// extern const int globe_var_x;

// namespace constants
// {
//     extern const double gravity;
// }

// namespace constants
// {
//     double getGravity();
// }

int main()
{
    // std::cout << Foo::doSomething(10, 15) << "\n";
    // std::cout << Goo::doSomething(10, 15) << "\n";
    // std::cout << ::doSomething(10, 15) << "\n";

    // Foo::helloThere();
    // std::cout << Foo::Goo::add(10, 14) << "\n";

    // namespace Active = Foo::Goo;
    // std::cout << Active::add(10, 14) << "\n";
    // std::cout << Goo::g_x << "\n";
    // std::cout << doSomething() << "\n";
    // std::cout << Goo::g_x << "\n"; // will be updated

    // std::cout << g_y << "\n";
    // std::cout << g_z << "\n";
    // doSomething();

    // sayHi();

    // std::cout << globe_var_y << "\n";
    // std::cout << globe_var_x;

    // std::cout << constants::getGravity();

    // std::cout << min(5, 6) << '\n';
    // std::cout << min(3, 2) << '\n';    

    // std::cout << "Please enter a radius:\n";
    // double radius{};
    // std::cin >> radius;

    // std::cout << "The circumference is " << 2 * radius * constants::pi << "\n";

    // incrementAndPrint();
    // incrementAndPrint();
    // incrementAndPrint();

    int a{getInteger()};
    int b{getInteger()};

    std::cout << a << " + " << b << " = " << (a+b) << "\n";

    return 0;
}