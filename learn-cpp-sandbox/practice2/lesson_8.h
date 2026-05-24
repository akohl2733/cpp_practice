#pragma once
#include <iostream>

void printDigitName(int x)
{
    switch(x)
    {
        case 1:
        case 2:
            std::cout << "one or two";
            return;
        case 3:
            std::cout << "three";
            return;
    }

    std::cout << "Nothing matched.";
}

void printCats(bool skip)
{
    if (skip)
        goto end;

    std::cout << "cats\n";

    end:
        ;
}