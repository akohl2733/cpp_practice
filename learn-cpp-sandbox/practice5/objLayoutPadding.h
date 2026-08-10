#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <string_view>

namespace structReview
{
    struct Employee
    {
        int id {};
        int age {};
        double wage {};
    };

    void doSomething()
    {
        Employee joe {1, 25, 25};

        std::cout << joe.age << " " << joe.wage << "\n";
    }
}

namespace nestedStructs
{
    struct Employee
    {
        int id {};
        int age {};
        double wage {};
    };

    struct Company
    {
        int numberOfEmployees {};
        Employee CEO {};
    };

    void doSomething()
    {
        Company tesla { 500000, { 1, 54, 1000000000 }};

        std::cout << "Tesla's CEO is " << tesla.CEO.age << " years old.\n";
    }
}

namespace ownerVsViewer
{
    struct Owner
    {
        std::string name {};
    };

    struct Viewer
    {
        std::string_view name {};
    };

    std::string getName()
    {
        std::cout << "Please print your name: ";
        std::string name {};
        std::cin >> name;
        return name;
    }

    void doSomething()
    {
        Owner o { getName() };
        std::cout << "Owner: " << o.name << "\n";

        // Viewer v { getName() };
        // std::cout << "Viewer: " << v.name << "\n";
    }
}

namespace structSizes
{
    struct Foo
    {
        short a {};
        int b {};
        double c {};
    };

    void doSomething()
    {
        std::cout << "The size of short is " << sizeof(short) << " bytes\n";
        std::cout << "The size of int is " << sizeof(int) << " bytes\n";
        std::cout << "The size of double is " << sizeof(double) << " bytes\n";

        std::cout << "The size of Foo is " << sizeof(Foo) << " bytes\n";
    }
}

namespace diffStructSizes
{
    struct Foo1
    {
        int a{};
        int b{};
        char c{};
    };

    struct Foo2
    {
        std::string b{};
        std::string a{};
        int c{};
    };

    void doSomething()
    {
        std::cout << "The size of Foo1 is " << sizeof(Foo1) << " bytes\n";
        std::cout << "The size of Foo2 is " << sizeof(Foo2) << " bytes\n";
    }
}