#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <cstddef>
#include <iterator>
#include <algorithm>
#include <cassert>

namespace dynamicMemory
{
    void allocate()
    {
        int* ptr { new int };
        *ptr = 10;
        std::cout << "The ptr points to " << *ptr << "\n";

        delete ptr;
    }

    void allocate2()
    {
        int* pointer { new int {10}};
        int* otherPointer( new int (10));

        *otherPointer = 14;

        std::cout << "The first pointer is " << *pointer << "\n";
        std::cout << "The first pointer is " << *otherPointer << " at address " << otherPointer << "\n";

        delete pointer;
        delete otherPointer;

        pointer = nullptr;
        otherPointer = nullptr;
    }
}

namespace dynamicMemoryArray
{
    void allocate()
    {
        std::cout << "Enter a positive integer: " << "\n";
        std::size_t length {};
        std::cin >> length;

        int* array { new int[length]{}};

        std::cout << "Ok, we allocated an array with length " << length << "\n";

        array[0] = 5;

        delete[] array;
    }

    void allocate2()
    {
        std::cout << "How many names do you want to submit?\n";
        std::size_t len{};
        std::cin >> len;

        auto* names { new std::string[len]{}};
        for (std::size_t i{0}; i < len; i++)
        {
            std::cout << "Name #" << i+1 << ": ";
            std::cin >> names[i];
        }

        std::sort(names, names+len);

        std::cout << "\nHere is your sorted list:\n";
        for (std::size_t i{0}; i < len; i++) {
            std::cout << "Name #" << i+1 << " " << names[i] << "\n";
        }

        delete[] names;
    }
}

namespace voidPointers
{
    void doSomething()
    {
        int nValue{};
        float fValue{};

        struct Something
        {
            int n;
            float f;
        };

        Something sValue{};

        void* ptr{};
        ptr = &nValue;
        ptr = &fValue;
        ptr = &sValue;

    }

    void doSomething2()
    {
        int value {10};
        void* voidPtr { &value };

        int* intPtr { static_cast<int*>(voidPtr)};

        std::cout << "The intPtr is " << *intPtr << "\n";
    }
}

namespace voidPointerUse
{
    enum class Type
    {
        tInt,
        tFloat,
        tCString
    };

    void printValue(void* ptr, Type type)
    {
        switch (type)
        {
            case Type::tInt:
                std::cout << "This ptr value is an int: " << *static_cast<int*>(ptr) << "\n";
                break;
            case Type::tFloat:
                std::cout << "This ptr value is a float: " << *static_cast<float*>(ptr) << "\n";
                break;
            case Type::tCString:
                std::cout << "This ptr value is a char: " << static_cast<char*>(ptr) << "\n";
                break;
            default:
                std::cerr << "printValue(): invalid type provided\n";
                assert(false && "type not found");
                break;
        }
    }

    void doSomething()
    {
        int intVal{5};
        float floatVal{7.4};
        char word[]{"Mollie"};

        printValue(&intVal, Type::tInt);
        printValue(&floatVal, Type::tFloat);
        printValue(word, Type::tCString);
    }

}