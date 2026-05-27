#include <iostream>
#include <string>
#include "lesson_11.h"
#include "lesson_f.h"
#include "lesson_12.h"

// #define PRINTVCAT(expr) { std::cout << #expr << " is an " << (is_lvalue(expr) ? "lvalue\n" : "rvalue\n"); }
#define isSmall(T) ( sizeof(T) <= 2 * sizeof(void*))

struct S
{
    double a;
    double b;
    double c;
};

int getInt() { return 5; }

int main() {

    // PRINTVCAT(5);
    // PRINTVCAT(getInt());
    // int x {5};
    // PRINTVCAT(x);
    // PRINTVCAT(std::string {"Hello"});
    // PRINTVCAT(++x);
    // PRINTVCAT(x++);
    // refPractice();
    // lvalueRefToConst();

    // const std::string y {"Pineapple"};
    // printValue(y);

    // int x{5};
    // std::cout << "The address of x is: " << &x << '\n';
    // printAddresses(x, x);

    // int y { 5 };
    // std::cout << y << "\n";
    // addOne(y);
    // std::cout << y << "\n";

    // int x{5};
    // const int z{10};

    // printVal(x);
    // printRef(z);

    std::cout << std::boolalpha;
    std::cout << isSmall(int) << "\n";

    double d {};
    std::cout << isSmall(d) << '\n';
    std::cout << isSmall(S) << '\n';

    return 0;
}