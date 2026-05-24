#include <iostream>
// #include <vector> // used array instead of vector for the constexpr at top
#include <string>
#include <array>
#include <algorithm>

namespace Calc
{
    constexpr std::array<std::string_view, 4> validResponses = {"m", "a", "d", "s"};

    void printWelcomeMessage()
    {
        std::cout << "=======================================\n";
        std::cout << "Welcome to the ultimate C++ calculator!\n";
        std::cout << "=======================================\n";
    }

    void toLower(std::string& s)
    {
        for (char &c : s){
            c = std::tolower((unsigned char)c);
        }
    }

    bool checkValidityOfResponse(const std::string& s)
    {
        auto it = std::find(validResponses.begin(), validResponses.end(), s);

        return it != validResponses.end();
    }
}