#pragma once

#include <iostream>
#include <bitset>

struct Fraction
{
    int numerator {};
    int denominator {};
};

void aliasPrac()
{
    using Color = int;
    
    constexpr Color red{0};
    constexpr Color green{1};
    constexpr Color blue{2};

    Color appleColor{red};
    Color shirtColor{green};

    std::cout << appleColor << std::endl;
    std::cout << shirtColor << std::endl;
}

void enumPrac1()
{
    enum Color
    {
        red,
        green,
        blue,
    };

    Color apple { red };
    Color shirt { green };
    Color cup { blue };

    std::cout << apple << std::endl;
    std::cout << shirt << std::endl;
    std::cout << cup << std::endl;
}

void enumPrac2()
{
    enum Pet
    {
        cat,
        dog,
        pig,
        whale,
    };

    enum Color
    {
        black,
        red,
        blue,
    };

    // Thse will not work because they are not values of correct enum
    // Pet myPet { black };
    // Color myShirt { pig };
}

enum FileReadResult
    {
        readResultSuccess,
        readResultErrorFileOpen,
        readResultErrorFileRead,
        readResultErrorFileParse,
    };

// FileReadResult readFileContents()
// {
// //     if (!openFile())
// //         return readResultErrorFileOpen;
// //     if (!readFile())
// //         return readResultErrorFileRead;
// //     if (!parseFile())
// //         return readErrorFileParse;

// //     return readResultSuccess;
// }

// good for defining items in video games
void enumPrac3()
{
    enum ItemType
    {
        sword,
        torch,
        potion,
    };

    ItemType holding{torch};
}

enum SortOrder
{
    alphabetical,
    alphabeticalReverse,
    numerical,
};

void sortData(SortOrder order)
{
    switch (order)
    {
        case alphabetical:
            std::cout << "Alpha" << std::endl;
            break;
        case alphabeticalReverse:
            std::cout << "Reverse" << std::endl;
            break;
        case numerical:
            std::cout << "Numerical" << std::endl;
            break;
        default:
            break;
    }
}

namespace Flags
{
    enum State
    {
        isHungray,
        isSad,
        isMad,
        isHappy,
        isLaughing,
        isAsleep,
        isDead,
        isCrying,
    };
}

void bitFlagPrac()
{
    std::bitset<8> me{};
    me.set(Flags::isHappy);
    me.set(Flags::isLaughing);

    std::cout << std::boolalpha;

    std::cout << "I am happy? " << me.test(Flags::isHappy) << "\n";
    std::cout << "I am laughing? " << me.test(Flags::isLaughing) << "\n";
}

// Add descriptions so no name collisions with blue in both (prefix important**)
// enum Color
// {
//     color_red,
//     color_green,
//     color_blue,
// };

// enum Feeling
// {
//     feeling_happy,
//     feeling_tired,
//     feeling_blue,
// };


// Better approach - use namespaces
namespace Color
{
    enum Color
    {
        red,
        green,
        blue,
    };
};

namespace Feeling
{
    enum Feeling
    {
        happy,
        tired,
        blue,
    };
}

namespace MonsterType
{
    enum MonsterType
    {
        orc,
        goblin,
        troll,
        ogre,
        skeleton,
    };
}

enum Animal
{
    cat = -3,
    dog,
    pig,
    horse = 5,
    giraffe = 5,
    chicken,
};

// best practice to initialize the zero index value as unknown in most cases
enum Winner
{
    winnerUnknown,
    player1,
    player2,
};

void castingEnums()
{
    enum Pet
    {
        cat,
        dog,
        pig,
        whale,
    };

    Pet pet { static_cast<Pet>(2) };
    std::cout << pet << std::endl;

    pet = static_cast<Pet>(3);
    std::cout << pet << std::endl;
}

namespace ColorSwitch
{
    enum Color
    {
        black,
        red,
        blue,
    };

    constexpr std::string_view getColorName(Color color)
    {
        switch (color)
        {
            case black: return "black";
            case red: return "red";
            case blue: return "blue";
            default: return "???";
        }
    }
}

namespace PetSwitches
{
    enum Pet
    {
        cat,
        dog,
        pig,
        whale,
    };

    constexpr std::string_view getPetName(Pet pet)
    {
        switch (pet)
        {
            case cat: return "Gato";
            case dog: return "Zeke";
            case pig: return "Wilbur";
            case whale: return "Yates";
            default: return "No Pet here";
        }; 
    }

    // constexpr std::optional<Pet> getPetFromString(std::string_view sv)
    // {
    //     if (sv == "Gato") return cat;
    //     if (sv == "Zeke") return dog;
    //     if (sv == "Wilbur") return pig;
    //     if (sv == "Yates") return whale;

    //     return {};
    // }
}

namespace WoojSwitch
{
    enum Pet
    {
        zeke,
        chlo,
        rodent,
        beaglehead
    };

    constexpr std::string_view getPetFromEnum(Pet petName)
    {
        switch(petName)
        {
            case zeke: return "WoojTard";
            case chlo: return "Goat";
            case rodent: return "Old Goat";
            case beaglehead: return "Woojbomb";
        }
    }

    // constexpr std::optional<Pet> getEnumFromString(std::string_view sv)
    // {
    //     if (sv == "WoojTard") { return zeke; }
    //     if (sv == "Goat") { return chlo; }
    //     if (sv == "Old Goat") { return rodent; }
    //     if (sv == "Woojbomb") { return beaglehead; }

    //     return {};
    // }
}

namespace UsingEnum
{
    enum Color
    {
        black,
        red,
        white,
    };

    // std::string_view getColor(Color color)
    // {
    //     using enum Color;

    //     switch (color)
    //     {
    //         case black: return "black";
    //         case red: return "red";
    //         case white: return "white";
    //         default: return "???";
    //     }
    // }
}

namespace BasicStruct
{
    struct Employee
    {
        int id {};
        int age {};
        double wage {};
        int whatever {};
    };

    void doRandomBs()
    {
        Employee joe {};
        joe.id = 473892;
        joe.age = 35;
        joe.wage = 45.67;

        Employee frank { 58932, 28, 23.45 };

        std::cout << joe.age + frank.age << '\n';
        std::cout << frank.whatever << '\n';

        if (frank.wage > joe.wage)
            std::cout << "Frank makes more than Joe.\n";
        else
            std::cout << "Joe makes more than Frank.\n"; 
    }
}

namespace StructOverload
{
    struct Employee
    {
        int id {};
        int age {};
        double wage {};
    };

    std::ostream& operator<<(std::ostream& out, Employee& e)
    {
        out << e.id << " " << e.age << " " << e.wage << "\n";
        return out;
    }

    void printStruct()
    {
        Employee joe { 2, 24 };
        std::cout << joe << "\n";
    }
}

namespace InitializerList
{
    struct Employee
    {
        int id {};
        int age {};
        double wage {};
    };

    void printWage()
    {
        Employee joe { .id = 543, .age = 45, .wage = 56.7 };

        std::cout << "Joes wage is " << joe.wage << "\n";
    }
}

namespace RepeatStructInitialize
{
    struct Foo
    {
        int a{};
        int b{};
        int c{};
    };

    std::ostream& operator<<(std::ostream& out, Foo& f)
    {
        out << f.a << " " << f.b << " " << f.c << '\n';
        return out;
    }

    void printInitialized()
    {
        Foo f { .a=10, .b=45, .c=849321 };

        Foo f2{f};
        Foo f3 = f;

        std::cout << f;
        std::cout << f2;
        std::cout << f3;
    }
}