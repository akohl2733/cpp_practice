# pragma once

#include <iostream>

const int g_x{};
constexpr int g_w{};

const int g_y{ 1 };
constexpr int g_z{ 2 };

// needs to be above Foo namespace to be recognized
void print()
{
    std::cout << "Hello, world!" << "\n";
}

// define Foo namespace
namespace Foo
{
    int doSomething(int x, int y)
    {
        return x + y;
    }

    void print()
    {
        std::cout << "Hello, there" << "\n";
    }

    void helloThere()
    {
        print();
        ::print();
    }
}

// define Goo namespace
namespace Goo
{
    int g_x{}; // define global variable here
    int doSomething(int x, int y)
    {
        return x - y;
    }
}

// define global namespace
void doSomething()
{
    std::cout << g_y << '\n';
    std::cout << g_z << '\n';
}

namespace Foo::Goo
{
    int add(int x, int y)
    {
        return x + y;
    }
}

void incrementAndPrint()
{
    static int s_value{1};
    ++s_value;
    std::cout << s_value << std::endl;
}

int getInteger()
{
    static bool s_isFirstCall{true};

    if (s_isFirstCall)
    {
        std::cout << "Enter an integer: ";
    }
    else
    {
        std::cout << "Enter another integer: ";
    }

    s_isFirstCall = !s_isFirstCall;

    int i{};
    std::cin >> i;
    return i;
}