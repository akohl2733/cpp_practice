#pragma once

#include <iostream>
#include <concepts>
#include <string_view>

int add(int x, int y)
{
    std::cout << "Int\n";
    return x + y;
}

double add(double x, double y)
{
    std::cout << "Double\n";
    return x + y;
}

void printInt(int x)
{
    std::cout << x << "\n";
}

void defaultArgs(int x=5, int y=10, int z=15)
{
    std::cout << x << " " << y << " " << z << std::endl;
}

void defArgs(std::string_view sv="This", double f=584.4382)
{
    std::cout << sv << " " << f << std::endl;
}

// template <typename T>
// T print(T x, T y)
// {
//     return (x > y) ? x : y;
// }

template <typename T>
requires std::integral<T> || std::floating_point<T>
T printVal(T x, T y)
{
    return (x > y) ? x : y;
}

template <typename T>
T printMax(T a, T b)
{
    return (a > b) ? a : b;
}

template<typename T, typename U>
auto max(T x, U y)
{
    return (x > y) ? x : y;
}

