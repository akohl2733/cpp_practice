#pragma once

#include <iostream>
#include <string_view>
#include <string>
#include <utility>


namespace DefaultMember
{
    struct Employee
    {
        int id;
        int age{};
        double wage{15.0};
    };

    void something()
    {
        Employee s;
        Employee s1{};

        std::cout << s.id << " " << s.age << " " << s.wage << "\n";
    }

}

namespace PassingStructs
{
    struct Employee
    {
        int id{};
        int age{};
        int salary{};
    };

    void printEmployee(Employee& e)
    {
        std::cout << "Id:       " << e.id << "\n";
        std::cout << "Age:      " << e.age << "\n";
        std::cout << "Salary:   " << e.salary << "\n";
    }

    void something()
    {
        Employee joe { 432, 45, 60000 };
        Employee jill { 9032, 30, 76000 };

        printEmployee(joe);
        std::cout << "\n";
        printEmployee(jill);
    }
}

namespace PassTempStructs
{
    struct Employee
    {
        int id{};
        int age{};
        int salary{};
    };

    void printEmployee(const Employee& e)
    {
        std::cout << "Id:       " << e.id << "\n";
        std::cout << "Age:      " << e.age << "\n";
        std::cout << "Salary:   " << e.salary << "\n";
    }

    void something()
    {
        printEmployee(Employee{ 5894, 76, 1000000});
        std::cout << "\n";
        printEmployee({ 43241, 56, 560000});
    }
}

namespace ReturnStruct
{
    struct Point3d
    {
        double x { 0.0 };
        double y { 0.0 };
        double z { 0.0 };
    };

    Point3d getZeroPoint()
    {
        return Point3d { 0.0, 0.0, 0.0 };
    }

    void something()
    {
        Point3d point { getZeroPoint() };

        if (point.x == 0.0 & point.y == 0.0 & point.z == 0.0)
            std::cout << "This worked as intended.\n";
        else
            std::cout << "This shit is busted.";
    }
}

namespace AdRevenue
{
    struct Advertising
    {
        int watched{0};
        double clickRate{0.0};
        double revPerAd{0.0};
    };

    void printResults(const Advertising& a)
    {
        double totalRevenue = a.watched * a.clickRate * a.revPerAd;
        std::cout << a.watched << " " << a.clickRate << a.revPerAd << '\n';
        std::cout << "You made $" << totalRevenue << " today!\n";
    }

    void something()
    {
        printResults(Advertising { 10000, 0.03, 3});
    }
}

namespace StructWithMember
{
    struct Company
    {
        struct Employee
        {
            int id {};
            int age {};
            double wage {};
        };

        int numberOfEmployees{};
        Employee CEO {};
    };

    void something()
    {
        Company myCompany {10, {89342, 28, 100.00}};
        std::cout << myCompany.CEO.age << '\n';
    }
}

namespace ViewVsOwn
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
        std::cout << "Enter a name: ";
        std::string name {};
        std::cin >> name;
        return name;
    }

    void something()
    {
        Owner o { getName() };
        std::cout << "The owner's name is " << "\n";

        // Viewer v { getName() };
        // std::cout << "The owner's name is " << "\n";
    }
}

namespace SizeOfStructs
{
    struct Foo1
    {
        short a{};
        int b{};
        short c{};
    };

    struct Foo2
    {
        short a{};
        short b{};
        int c{};
    };

    void something()
    {
        // These are different - due to padding - can be weirder behavior
        std::cout << sizeof(Foo1) << "\n";
        std::cout << sizeof(Foo2) << "\n";
    }
}

namespace RefSelect
{
    struct Employee
    {
        int id {};
        int age {};
        double wage {};
    };

    void printEmployee(const Employee& e)
    {
        std::cout << "Id:       " << e.id << "\n";
        std::cout << "Age:      " << e.age << "\n";
        std::cout << "Wage:     " << e.wage << "\n";
    }

    void something()
    {
        Employee joe { 1, 34, 65000.00 };

        ++joe.age;
        joe.wage = 68000;

        printEmployee(joe);
    }
}

namespace PointerSelect
{
    struct Employee
    {
        int id {};
        int age {};
        double wage {};
    };

    void something()
    {
        Employee joe { 1, 34, 65000.00 };

        ++joe.age;
        joe.wage = 68000;

        Employee* ptr { &joe };
        // std::cout << (*ptr).age << "\n";     // Must dereference (ugly)
        std::cout << ptr->age << "\n";          // Much cleaner with -> syntax!
    }
}

namespace ChainingPointerOperator
{
    struct Point
    {
        double x {};
        double y {};
    };

    struct Triangle
    {
        Point* a {};
        Point* b {};
        Point* c {};
    };

    void something()
    {
        Point a {1,2};
        Point b {3,7};
        Point c {10,2};

        Triangle tr { &a, &b, &c };
        Triangle* ptr { &tr };

        std::cout << (*(*ptr).c).y << "\n";
        std::cout << ptr->c->y << "\n";
    }
}

namespace MixingPointers
{
    struct Paw
    {
        int claws{};
    };

    struct Animal
    {
        std::string name{};
        Paw paw{};
    }; 

    void something()
    {
        Animal puma { "Puma", { 5 } };
        Animal* ptr { &puma };

        std::cout << (*ptr).name << "\n";
        std::cout << ptr->paw.claws << "\n";
    }
}

namespace OverloadTrad
{
    struct Pair
    {
        int first{};
        int second{};
    };

    // struct Pair // compile error: erroneous redefinition of Pair
    // {
    //     double first{};
    //     double second{};
    // };

    constexpr int max(Pair p)
    {
        return (p.first < p.second ? p.second : p.first);
    }
}

namespace ClassTemplates
{
    template <typename T>
    struct Pair
    {
        T first{};
        T second{};
    };

    // constexpr int max(Pair<int> p1)
    // {
    //     return p1.first > p1.second ? p1.first : p1.second;
    // }

    // constexpr double max(Pair<double> p1)
    // {
    //     return p1.first > p1.second ? p1.first : p1.second;
    // }

    template<typename T>
    constexpr T max(Pair<T> p1)
    {
        return p1.first > p1.second ? p1.first : p1.second;
    }

    void something()
    {
        Pair<int> p1 { 1, 2 };
        Pair<double> p2 { 1.4, 2.5 };
        Pair<double> p3 { 1, 3.5 };
    }
}

namespace ClassTempPrac
{
    template <typename T, typename U>
    struct Pair
    {
        T first {};
        U second {};
    };

    template <typename T, typename U>
    void something(Pair<T, U> p1)
    {
        std::cout << p1.first << " " << p1.second << "\n";
    }
}

namespace MoreTemplate
{
    template <typename T, typename U>
    struct Pair
    {
        T first {};
        U second {};
    };

    struct Point
    {
        int first {};
        int second {};
    };

    template <typename T>
    void something(T p)
    {
        std::cout << p.first << " " << p.second << "\n";
    }
}

namespace Pairs
{
    template <typename T, typename U>
    void print(std::pair<T, U> p)
    {
        std::cout << p.first << " " << p.second << "\n";
    }

    void something()
    {
        std::pair<int, double> p1 { 100, 56.7 };
        std::pair<double, int> p2 { 106.7, 576382 };
        std::pair<double, double> p3 { 7.5, 56 };

        print(p1);
        print(p2);
        print(p3);
    }
}

namespace Alias
{
    template <typename T>
    struct Pair
    {
        T first {};
        T second {};
    };

    template <typename T>
    using Coord = Pair<T>;

    template <typename T>
    void print(const Coord<T>& p)
    {
        std::cout << p.first << " " << p.second << "\n";
    }

    void something()
    {
        Coord<int> c { 1, 5 };
        print(c);
    }
}

namespace MonstersQuiz
{
    enum options
    {
        ogre,
        orc,
        dragon,
        giant_spider,
        slime
    };

    struct Monster
    {
        options o {};
        std::string name {};
        int health {};
    };

    constexpr std::string_view switchOption(options o){
        switch (o)
        {
            case ogre: return "Ogre";
            case orc: return "Orc";
            case dragon: return "Dragon";
            case giant_spider: return "Big ahh spider";
            case slime: return "Slime";
            default: return "???";
        }
    }

    void print(const Monster& monster)
    {
        std::cout << "Your monster is       : " << switchOption(monster.o) << "\n"; 
        std::cout << "Your name is          : " << monster.name << "\n"; 
        std::cout << "Your remaining health : " << monster.health << "\n"; 
    }

    void something()
    {
        Monster m1 { orc, "Bartholomeau", 356 };
        Monster m2 { giant_spider, "Lucas", 34 };
        Monster m3 { slime, "Muk", 45 };

        print(m1);
        std::cout << "\n";
        print(m2);
        std::cout << "\n";
        print(m3);
    }
}