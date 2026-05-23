#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <stdexcept>

void writeValue(int x)
{
    std::cout << x << std::endl;
}

void goThroughVector(std::vector<std::string>& lst) {
    for (std::string member: lst) {
        std::cout << member << std::endl;
    }
}

int testIntSize()
{
    std::int16_t x { 30000 };
    
    return x;
}

void setRGB(int r, int b, int a)
{
    if (r < 0 || r > 255 || b < 0 || b > 255 || a < 0 || a > 255) {
        throw std::out_of_range("The inputs must all be positive and less than 255");
    }

    std::uint8_t validR = static_cast<std::uint8_t>(r);
    std::cout << "Successfully set RGB color\n";
}

void charToInt(char c)
{
    int newInt = static_cast<int>(c);

    std::cout << "The char has a value of " << newInt << std::endl;
}

void unsignSign(unsigned int u, int s)
{
    int newSigned = static_cast<int>(u);
    std::cout << u << " --> " << newSigned << std::endl;

    unsigned int newUnsigned = static_cast<unsigned int>(s);
    std::cout << s << " --> " << newUnsigned << std::endl;
}