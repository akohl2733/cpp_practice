#include <iostream>
#include <optional>
#include "lesson_12_pt_2.h"


int main() {

    // printAddressOf();
    // typeMatch();
    // changeDir();
    // refVsPoint();
    // printPtrSizes();
    // createNullPtr();
    // bustedPtr();
    // extraConstPtrs();
    // diffPtrs();

    // const std::string str{ "Hello, world" };
    // // printByReference(str);

    // const std::string* ptr {&str};
    // printByAddress(ptr);

    // int value = 10;
    // changeValue(&value);
    // std::cout << value << std::endl;

    // char c { 'g' };
    // int x = static_cast<short>(c);
    // int* ptr { &x };

    // printNullPtr(ptr);

    // int x{5};
    // printConstPtr(&x);
    // printConstPtr(nullptr);

    // int* ptr { &x };
    // optionalParam(ptr);
    // optionalParam();

    // int x { 64 };
    // functionOverload();
    // functionOverload(x);

    // int x{5};
    // int* ptr { &x };
    // std::cout << "ptr is " << (ptr ? "not null\n" : "null\n");
    // nullify(ptr);
    // std::cout << "ptr is " << (ptr ? "not null\n" : "null\n");

    // printnullptr(nullptr);
    // int x{5};
    // int* ptr { &x };
    // printnullptr(ptr);
    // ptr = nullptr;
    // printnullptr(ptr);

    // std::cout << "This program is name " << getProgramName() << '\n';

    // const int& ref { returnByConstReference() };
    // std::cout << ref;

    // const int& id1 { getNextId() };
    // const int& id2 { getNextId() };
    // std::cout << id1 << id2 << std::endl;

    // std::string hello { "Hello" };
    // std::string world { "World" };
    // std::cout << firstAlphabetical(hello, world) << "\n";

    // int a{5};
    // int b{6};
    // max(a, b) = 7;
    // std::cout << a << " " << b << std::endl;

    // double sin { 0.0 };
    // double cos { 0.0 };
    // double degrees{};
    // std::cout << "Enter a number of degrees:\n";
    // std::cin >> degrees;
    // getSinCos(degrees, sin, cos);
    // std::cout << sin << std::endl;
    // std::cout << cos << std::endl;

    // testReciprocal(5.0);
    // testReciprocal(-4.0);
    // testReciprocal(0.0);

    // std::cout << doIntDivision(89, 0) << '\n';
    // std::cout << doIntDivision(89, 100) << '\n';

    // std::optional<int> result1 { doIntegerDivision(20, 5) };
    // if (result1)
    //     std::cout << "Result 1: " << *result1 << '\n';
    // else 
    //     std::cout << "Result 1 Failed\n";
    // std::optional<int> result2 { doIntegerDivision(20, 0) };
    // if (result2)
    //     std::cout << "Result 2: " << *result2 << '\n';
    // else 
    //     std::cout << "Result 2 Failed\n";

    // stdOptionalPrac();

    // printIdNumber();
    // int userId {34};
    // printIdNumber(userId);
    // printIdNumber(63);  // can pass an rvalue - cannot do when parameter is expecting an rvalue

    // printWorkerId();
    // Employee e { "James", 674324 };
    // printWorkerId(e);
    // printWorkerId({ "Andrew", 8439825 });

    int x {1};
    int y {11};
    swap(x, y);

    std::cout << "X is: " << x << "-- Y is: " << y << std::endl;

    return 0;
}