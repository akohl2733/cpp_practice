#pragma once

#include <string>
#include <iostream>

template <typename T>
constexpr bool is_lvalue(T&)
{
    return true;
}

template <typename T>
constexpr bool is_lvalue(T&&)    // peep the double && operator
{
    return false;
}

void refPractice()
{
    int x {5};
    
    {
        int& ref {x};
        std::cout << ref << '\n';
    }

    std::cout << x << "\n";
}

void lvalueRefToConst()
{
    const double& r1 {5};

    std::cout << r1 << '\n';

    char c {'a'};
    const int& r2 {c};

    std::cout << r2 << '\n';
}

void printValue(const std::string& y)
{
    std::cout << y << '\n';
}

void printAddresses(int val, int& ref)
{
    std::cout << "The address of the value parameter is: " << &val << "\n";
    std::cout << "The address of the ref parameter is: " << &ref << "\n";
}

void addOne(int& y)
{
    ++y;
}

// void printRef(const int& x)
// {
//     std::cout << x << '\n';
// }

void printVal(double d)
{
    std::cout << d << '\n';
}

void printRef(const double& d)
{
    std::cout << d << '\n';
}