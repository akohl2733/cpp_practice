#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <type_traits>

void printInt(int x)
{
    std::cout << x << "\n";
}

void someFcn(int i)
{
}

void print(unsigned int u)
{
    std::cout << u << "\n";
}


// use type alias to clean up verbose and complex types like this
using VectPairSI = std::vector<std::pair<std::string, int>>;

bool hasDuplicates(VectPairSI pairlist)
{
    return false;
}

auto add(unsigned short x, char y)
{
    return x + y;
}

// same thing but use trailing return type for readability
std::common_type_t<int, double> compare(int, double);
auto compare(int, double) -> std::common_type_t<int, double>;

// define functions this way for readability
auto add(int x, int y) -> int;
auto divide(double x, double y) -> double;
auto doRandomStuff(short x, std::string_view str) -> void;