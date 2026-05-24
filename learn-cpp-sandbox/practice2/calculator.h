#pragma once
#include <string>

namespace Calc
{
    constexpr double add(double x, double y) { return x + y; }
    constexpr double subtract(double x, double y) { return x - y; }
    constexpr double multiply(double x, double y) { return x * y; }
    constexpr double divide(double x, double y) { return x / y; }

    void printWelcomeMessage();
    bool checkValidityOfResponse(const std::string& s);
    void toLower(std::string& s);
}