#include <iostream>
#include <vector>
#include <string>
#include "calculator.h"

int main()
{

    // printInt(2);

    // short s{ 3 };
    // printInt(s);

    // float f{3.6f};
    // printInt(f);

    // printInt('d');
    // printInt(true);

    // these will both work
    // int n = static_cast<int>(static_cast<long>(3));
    // std::cout << n << "\n";
    // char c = static_cast<char>(static_cast<double>('c'));
    // std::cout << c << "\n";

    // int y = static_cast<int>(static_cast<unsigned int>(-5));

    // unsigned int u = static_cast<unsigned int>(-10); // 4294967286
    // int q = static_cast<int>(u); // back to -10    

    // double d {5.0};
    // int i {static_cast<int>(d)};

    // std::cout << "Enter an integral value: ";
    // int n{};
    // std::cin >> n; // this will print a overflowed value if negative
    // print(n);

    // VectPairSI pairlist;

    // constexpr double a { 3.4 };
    // type deduction
    // auto b { a };
    // const auto c { a };
    // constexpr auto d { a };

    Calc::printWelcomeMessage();

    std::cout << "Please enter a number: ";
    double x{};
    std::cin >> x;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "What would you like to do to " << x << "?\n";
    std::cout << "Add (a), Subtract (s), Multiply (m), Divide (d)\n"; 
    std::string s{};
    std::getline(std::cin, s);

    Calc::toLower(s);

    bool isResOk = Calc::checkValidityOfResponse(s);

    if (!isResOk) {
        std::cout << "Please enter a valid value.";
        return 0;
    }

    std::cout << "Please enter another number: ";
    double y{};
    std::cin >> y;

    if (s == "s")
        std::cout << Calc::subtract(x, y);
    else if (s == "a")
        std::cout << Calc::add(x, y);
    else if (s == "m")
        std::cout << Calc::multiply(x, y);
    else if (s == "d")
        std::cout << Calc::divide(x, y);
    else
        std::cout << "Something went wrong";

    return 0;
}