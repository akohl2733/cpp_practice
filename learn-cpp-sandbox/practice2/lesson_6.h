#pragma once

#include <iostream>
#include <string>
#include <cassert>
#include <cstdint>
#include <limits>

int getRemainder(int x, int y)
{
    if ((x % y) != 0) {
        std::cout << x << " is not divisble by " << y << std::endl;
        return 0;
    }
    std::cout << x << " is divisble by " << y << std::endl;
    return 0;
}

void testDoubleIntake()
{
    std::cout << "Please enter an integer:\n";
    double x{};
    std::cin >> x;

    std::cout << "Please enter another integer:\n";
    double y{};
    std::cin >> y;

    if (x / y == 1){
        std::cout << x << " is the same as " << y << "\n";
    } else {
        std::cout << x << " is a diff num than " << y << "\n";
    }
}

// Does checking for negative values but not int overflow
constexpr std::int64_t powint(std::int64_t base, std::int64_t exp)
{
    assert(exp >= 0 && "powint: exp parameter has negative value");

    // Handle base case
    if (base == 0){
        return (exp == 0) ? 1 : 0;
    }

    std::int64_t result{1};
    while (exp > 0) {
        if (exp & 1)    // if exp is odd
            result *= base;
        exp /= 2;
        base *= base;
    }

    return result;
}

// Safer - does checking for negative values and integer overflow
constexpr std::int64_t powerIntBetter(std::int64_t base, std::int64_t exp)
{
    assert(exp >= 0 && "powint: exp parameter has negative value.");

    if (base == 0){
        return (exp == 0) ? 1 : 0;
    }

    std::int64_t res{1};

    bool negativeResult{ false };

    if (base < 0){
        base = -base;
        negativeResult = true;
    }

    while (exp > 0){
        if (exp & 1)
        {
            if (res > std::numeric_limits<std::int64_t>::max() / base)
            {
                std::cerr << "powIntBetter(): result overflowed\n";
                return std::numeric_limits<std::int64_t>::max();
            }
            res *= base;
        }

        exp /= 2;

        if (exp <= 0)
            break;

        if (base > std::numeric_limits<std::int64_t>::max() / base)
        {
            std::cerr << "powIntBetter: base overflowed\n";
            return std::numeric_limits<std::int64_t>::max();
        }
        base *= base;
    }

    if (negativeResult)
        return -res;

    return res;
}

// my take from memory and logic understanding
constexpr std::int64_t myTake(std::int64_t base, std::int64_t exp)
{
    assert(base >= 0 && "myTake() base must be a positive int.");

    if (base == 0)
        return (exp == 0) ? 1: 0;

    std::int64_t res{1};

    bool negativeRes{ false };

    if (base < 0)
    {
        base = -base;
        negativeRes = true;
    }

    while (exp > 0)
    {
        if (exp & 1)
        {
            if (res > std::numeric_limits<std::int64_t>::max() / base)
            {
                std::cerr << "myTake() result overflowed.\n";
                return std::numeric_limits<std::int64_t>::max();
            }
            res *= base;
        }

        exp /= 2;

        if (exp <= 0)
            break;

        if (base > std::numeric_limits<std::int64_t>::max() / base)
        {
            std::cerr << "myTake() result overflowed.\n";
            return std::numeric_limits<std::int64_t>::max();
        }
        base *= base;
    }

    if (negativeRes)
        res = -res;
        
    return res;
}

void returnIncrement()
{
    int x{5};
    int y{5};

    std::cout << x << " " << y << "\n";
    std::cout << ++x << " " << --y << "\n"; // prefix
    std::cout << x << " " << y << "\n";
    std::cout << x++ << " " << y-- << "\n"; // postfix
    std::cout << x << " " << y << "\n";
}

void incrementPractice()
{
    int x{5};
    for (int i{0}; i < x; ++i)
    {
        std::cout << i << "\n";
    }
}

void conditionalPractice()
{
    constexpr bool bigClassroom { false };
    int classSize{};

    if (bigClassroom){
        classSize = 20;
    } else {
        classSize = 14;
    }

    std::cout << "The class size is: " << classSize << "\n";
}

void typeMatchingConditional()
{
    std::cout << (true ? 1 : 2) << '\n';
    std::cout << (false ? 1 : 2.2) << '\n';
    std::cout << (true ? -1 : 2u) << '\n';

    int x{4};

    std::cout << ((x!=5) ? std::to_string(x) : std::string{"x is 5"}) << std::endl;
}

void comparingFloatingPoint()
{
    constexpr double d1{100.0 - 99.9};
    constexpr double d2{ 10.0 - 9.9 };

    if (d1 == d2)
        std::cout << "d1 == d2" << "\n";
    else if (d1 > d2)
        std::cout << "d1 > d2" << "\n";
    else if (d1 < d2)
        std::cout << "d1 < d2" << "\n";
}