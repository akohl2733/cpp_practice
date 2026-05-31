#pragma once

#include <iostream>
#include <cassert>
#include <cstddef>
#include <cmath>
#include <string_view>
#include <limits>
#include <optional>

void printAddressOf(){

    int x{5};
    std::cout << x << "\n";

    int* ptr{&x};
    std::cout << *ptr << "\n";
}

void typeMatch()
{
    int i{5};
    double d{7.0};

    int x = static_cast<int>(d);

    int* ptr{&x};
    std::cout << *ptr << std::endl;
}

void changeDir()
{
    int x {5};
    int* ptr {&x};

    std::cout << x << std::endl;
    std::cout << *ptr << std::endl;

    int y{6};
    // ptr = &y;
    *ptr = 6; // This will change x because it is de-referenced!

    std::cout << x << std::endl;
    std::cout << *ptr << std::endl;

}

void refVsPoint()
{
    int x { 5 };
    int& ref {x};
    int* ptr {&x};

    std::cout << x;
    std::cout << ref;
    std::cout << *ptr << std::endl;

    ref = 6;

    std::cout << x;
    std::cout << ref;
    std::cout << *ptr << std::endl;

    *ptr = 7;

    std::cout << x;
    std::cout << ref;
    std::cout << *ptr << std::endl;

}

void printPtrSizes()
{
    char* c{};
    int* p{};
    long double* d{};

    std::cout << sizeof(c) << std::endl;
    std::cout << sizeof(p) << std::endl;
    std::cout << sizeof(d) << std::endl;
}

void createNullPtr()
{
    int x {5};
    int* ptr { &x };

    if (!ptr)
        std::cout << "ptr is null\n";
    else
        std::cout << *ptr << std::endl;

    int* nullPtr {};
    std::cout << "nullPtr is " << (nullPtr==nullptr ? "null\n" : "not null\n");
}

void bustedPtr()
{
    int* ptr {};

    {
        int x{5};
        ptr = &x;
    }

    if (ptr)
        std::cout << *ptr << std::endl;
}

void constsAndPtrs()
{
    const int x{7};
    const int* ptr { &x };

    const int y{8};
    ptr = &y;

    std::cout << *ptr << std::endl;

}

void constPtrs()
{
    int x{5};
    int* const ptr { &x };

    *ptr = 6;   // This works because the x value is not a const - cannot reassign to another address tho

    std::cout << *ptr << std::endl;
}

void extraConstPtrs()
{
    const int x{8};
    const int* const ptr { &x };

    std::cout << *ptr << std::endl;

}

void diffPtrs()
{
    int v{5};

    int* ptr0 { &v };
    const int* ptr1 { &v };
    int* const ptr2 { &v };
    const int* const ptr3 { &v };

    std::cout << *ptr0  << " " << *ptr1 << " " << *ptr2 << " " << *ptr3 << std::endl;
}

void printByReference(const std::string& ref)
{
    std::cout << ref << std::endl;
}

void printByAddress(const std::string* ptr)
{
    std::cout << *ptr << "\n";
}

void changeValue(int* ptr)
{
    std::cout << *ptr << std::endl;
    *ptr = 6;
}

void printNullPtr(int* ptr)
{
    if (!ptr)
        return;
    std::cout << *ptr << "\n";
}

void printConstPtr(const int* ptr)
{

    if (!ptr)
        return;
    
    std::cout << *ptr << std::endl;
}

void optionalParam(const int* id=nullptr)
{
    if (!id)
        std::cout << "Your ID number is unknown\n";
    else
        std::cout << "Your ID number is " << *id << std::endl;
}

void functionOverload()
{
    std::cout << "Your ID is not known.\n";
}

void functionOverload(int i)
{
    std::cout << "Your ID is " << i << ".\n";
}

void nullify(int*& refptr)  // reference to a pointer lol
{
    refptr = nullptr;
}

void printnullptr(std::nullptr_t)
{
    std::cout << "int print(std::nullptr_t)\n";
}

void printnullptr(int*)
{
    std::cout << "in print(int*)\n";
}

const std::string& getProgramName()
{
    static const std::string s_programName { "Calculator" };    // static ensures this exists outside the function returning the reference

    return s_programName;
}

// const int& returnByConstReference()
// {
//     return 5;
// }

const int& getNextId()
{
    static int s_x{ 0 };
    ++s_x;
    return s_x;
}

const std::string& firstAlphabetical(const std::string& a, const std::string& b)
{
    return (a < b) ? a : b;
}

int& max(int& x, int& y)
{
    return (x > y) ? x : y;
}

void getSinCos(double degrees, double& sinOut, double& cosOut)
{
    constexpr double pi { 3.1415926 };
    double radians = degrees * pi / 180.0;

    sinOut = std::sin(radians);
    cosOut = std::cos(radians);
}

void dontDoAnything()
{
    const double a {3.0};
    auto b { a };   // const will be dropped here - remember these are not refs/ptrs so not same thing

    constexpr double c { 7.8 };
    auto d { c }; // constexpr will be dropped here

    constexpr double e { 23.5 };
    constexpr auto f { e }; // can be added back
}

std::string& getRefEx();
const std::string& getConstRefEx();
std::string* getPtrType();

void typeDeductionRefs()
{
    // auto ref { getRefEx() };    // this will drop reference ( std::string not std::string& )
    // auto& ref2 { getRefEx() };  // reference is initially dropped but re-added

    // // top-level consts - apply to obj itself
    // const int x{};
    // int* const ptr{};

    // // low-level consts - apply to obj being referenced to
    // const int& ref{};
    // const int* ptr2{};

    // // auto ref1{ getConstRefEx() };   // std::string (ref dropped, then top level const dropped from res)
    // // const auto ref2 { getConstRefEx() };    // ref dropped, const dropped and reapplied
    // // auto& ref3 { getConstRefEx() }; // ref dropped and reapplied, low-level const not dropped
    // // const auto& ref4 { getConstRefEx() };   // ref dropped and reapplied, low-level const not dropped

    // auto ptr1 { getPtrType() };
    // auto* ptr3 { getPtrType() };    // These will both return std::string* no difference

    // auto ptr4 { *getPtrType() };    // std::string because we dereference
    // // auto* ptr5 { *getPtrType() };   // not going to work - std::string is not the same as ptr type

}

double reciprocal( double x )
{
    if ( x == 0.0 )
    {
        return 0.0;
    }
    return 1.0 / x;
}

void testReciprocal( double d )
{
    double result { reciprocal(d) };
    std::cout << "The reciprocal of " << d << " is ";
    if ( result != 0.0 )
        std::cout << result << "\n";
    else
        std::cout << "undefined.\n";
}

int doIntDivision(int x, int y)
{
    if (y == 0)
        return std::numeric_limits<int>::lowest();
    return x / y;
}

std::optional<int> doIntegerDivision(int x, int y)
{
    if ( y == 0 )
        return {};
    return x / y;
}

void stdOptionalPrac()
{
    std::optional<int> o1 { 5 };
    std::optional<int> o2 {};
    std::optional<int> o3 { std::nullopt };

    if (o1.has_value())
        std::cout << "o1 has a value\n";
    else
        std::cout << "o1 is empty\n";

    std::cout << *o1 << std::endl;
    std::cout << o3.value_or(42) << std::endl;
}

void printIdNumber(std::optional<const int> id = std::nullopt)
{
    if (id)
        std::cout << "Your ID number is " << *id << ".\n";
    else
        std::cout << "Your ID number is not known.\n";
}

struct Employee
{
    std::string name {};
    int id;
};

void printWorkerId()
{
    std::cout << "Your ID number is not known.\n";
}

void printWorkerId(const Employee& e)
{
    std::cout << "Your ID number is " << e.id << std::endl;
}

void swap(int& x, int& y)
{
    if (x > y)
        return;
    const int temp {x};
    x = y;
    y = temp;
}