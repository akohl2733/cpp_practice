#pragma once
#include <iostream>
#include <type_traits>

constexpr double calculateCirc(double diameter)
{
    constexpr double pi { 3.14159 };
    
    return pi * diameter;
}

consteval int getMax(int x, int y)
{
    return (x > y) ? x : y;
}

constexpr int compare(int x, int y)
{
    if (std::is_constant_evaluated())
        return x + y;
    return x - y;
}

consteval int doSomething(int x, int y)
{
    x = x + 2;

    int z { x + y };

    if (x > y)
        z = z - 1;
    
    return x;
}