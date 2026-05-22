#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include "square.h"
#include "wave.h"

std::string toLowerCase(std::string& s);

int main()
{

    std::string option {};
    std::string choice {};

    std::cout << "What would you want for dinner? Choose from [Burger, Pizza, Tacos]" << std::endl;
    std::cin >> option;
    choice = toLowerCase(option);

    if (choice == "pizza") {
        std::cout << "Boring" << std::endl;
    } else if (choice == "burger") {
        std::cout << "You must hate cows" << std::endl;
    } else if (choice == "tacos") {
        std::cout << "hmm" << std::endl;
    } else {
        std::cout << "brick" << std::endl;
    }
    return 0;
}

std::string toLowerCase(std::string& s)
{
    for (char &c : s) {
        c = std::tolower(c);
    }

    return s;
}