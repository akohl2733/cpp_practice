#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <utility>
#include <algorithm>
#include <vector>
#include <optional>

namespace FirstClass
{
    class Date
    {
        public:
        int m_day{};
        int m_month{};
        int m_year{};
    };

    void printDate(const Date& d)
    {
        std::cout << d.m_month << "/" << d.m_day << "/" << d.m_year << "\n";
    }

    void something()
    {
        Date d { 3, 12, 25 };
        printDate(d);
    }
}

namespace MemberFunctions
{
    struct Date
    {
        int m_day {};
        int m_month {};
        int m_year {};

        void printDate()
        {
            std::cout << m_month << "/" << m_day << "/" << m_year << "\n";
        }
    };

    void something()
    {
        Date d1 { 27, 9, 2018 };
        Date d2 { 30, 1, 2024 };

        d1.printDate();
        d2.printDate();
    }
}

namespace MemberFunctionsTwo
{
    struct Person
    {
        std::string name {};
        int age {};
        bool married {};

        void printMarriedTo(const Person& p)
        {
            std::string_view married_str;
            if (married == 1)
                married_str = "True";
            else
                married_str = "False";

            std::cout << name << " is in a relationship with " << p.name << ":  " << married_str << "\n";
        }
    };

    void something()
    {
        Person joe { "Joe", 32, true };
        Person lucy { "Lucy", 28, true };

        joe.printMarriedTo(lucy);
    }
}

namespace OverloadedMember
{
    struct Date
    {
        int m_month {};
        int m_day {};
        int m_year {};

        void print()
        {
            std::cout << m_month << "/" << m_day << "/" << m_year << "\n";
        }

        void print(std::string_view prefix)
        {
            std::cout << prefix << m_month << "/" << m_day << "/" << m_year << "\n";
        }
    };

    void something()
    {
        Date halloween { 10, 31, 2024 };
        halloween.print();

        std::string_view s { "Halloween is: "};
        halloween.print(s);
    }
}

namespace BasicMember
{
    struct Foo
    {
        void printHi() { std::cout << "Hello\n"; };
    };

    void something()
    {
        Foo f {};
        f.printHi();
    }
}

namespace MemberFunctionQuiz
{
    struct IntPair
    {
        int first {};
        int second {};

        void print()
        {
            std::cout << "Pair(" << first << ", " << second << ")\n";
        }

        bool isEqual(const IntPair& i)
        {
            if (first == i.first & second == i.second)
                return true;
            return false;
        }
    };

    void something()
    {
        IntPair p1 {1, 2};
        IntPair p2 {3, 4};

        std::cout << "p1: ";
        p1.print();

        std::cout << "p2: ";
        p2.print();

        std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
        std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");
    }
}

namespace ConstMemberFunc
{
    struct Employee
    {
        int id {};
        int age {};
        std::string name {};

        void print() const
        {
            std::cout << id << " " << age << " " << name << "\n";
        }
    };

    void something()
    {
        const Employee e { 54, 25, "Andrew Kohl"};

        e.print();
    }
}

namespace ConstMemberFunctionTwo
{
    struct Employee
    {
        int id {};
        int age {};
        std::string name {};

        void print() const
        {
            std::cout << id << " " << age << " " << name << "\n";
        }
    };

    void doSomething(Employee* e)
    {
        (*e).print();
    }

    void something()
    {
        Employee ak { 1, 25, "Andy Roo"};
        doSomething(&ak);
    }
}

namespace ClassDefaults
{
    class Date
    {
        private:
            int m_m {1};
            int m_d {1};
            int m_y {2026};

            int getMaxDaysInMonth(int month, int year)
            {
                // February check - could be 28 or 29
                if (month == 2)
                {
                    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                    {
                        return 29;
                    }
                    return 28;
                }
                // check for months with 30 max
                const std::vector<int> thirtyDays = { 4, 6, 9, 11 };
                if (std::ranges::find(thirtyDays, month) != thirtyDays.end())
                {
                    return 30;
                }
                // month is other
                return 31;
            }

        public:

            Date(int month, int day, int year) 
            {
                setMonth(month);
                setDay(day);
                setYear(year);
                std::cout << "Date initialized successfully!\n";
                print();
            }

            int getMonth() { return m_m; }
            int getDay() { return m_d; }
            int getYear() { return m_y; }

            void setMonth(int month)
            {
                if (month > 12 || month < 1)
                {
                    std::cout << "Month is not valid.\n";
                    return;
                }
                m_m = month;
            }

            void setDay(int day)
            {
                int maxDays = getMaxDaysInMonth(m_m, m_y);
                if (day > maxDays || day < 1)
                {
                    std::cout << "Invalid day.\n";
                    return;
                }
                m_d = day;
            }

            void setYear(int year)
            {
                if (year > 2026 | year < 1)
                {
                    std::cout << "Year is not valid.\n";
                    return;
                }
                m_y = year;

                if (m_m == 2 && m_d == 29 && getMaxDaysInMonth(m_m, m_y) == 28)
                {
                    std::cout << "WARNING: max days for February adjusted to 28.\n";
                    return;
                }
            }

            void print() const
            {
                std::cout << m_m << "/" << m_d << "/" << m_y << "\n";
            }
    };

    void something()
    {
        Date d { 12, 25, 2026 };
        int day = d.getDay();
        int month = d.getMonth();
        int year = d.getYear();

        d.setDay(43);
        d.setMonth(3);
        d.setYear(2027);

        d.print();
    }
}

namespace PubVsPrivate
{
    class Date
    {
        private:
        
            int m_month { 10 };
            int m_day { 31 };
            int m_year { 2012 };

        public:

            void print()
            {
                std::cout << m_year << ": I'm too lazy for rest\n";
            }
    };

    void something()
    {
        Date d{};
        d.print();
    }
}

namespace ClassAccessLevel
{
    class Person
    {
        private:
            std::string m_name{};
            int m_age {};
            std::string m_loc {};

        public:

            Person(std::string_view name, int age, std::string_view loc)
            {
                setName(name);
                setAge(age);
                setLoc(loc);
                std::cout << name << " was initialized.\n\n";
            }

            const std::string& getName() const { return m_name; }
            void setName(std::string_view name) { m_name = name; }

            int getAge() const { return m_age; }
            void setAge(int age) { m_age = age; }

            const std::string& getLoc() const { return m_loc; }
            void setLoc(std::string_view loc) { m_loc = loc; }

            void printAssoc(const Person& p)
            {
                std::cout << m_name << " lives with " << p.m_name << " in " << m_loc << "\n";
            }
    };

    void something()
    {
        Person p1 { "Andrew", 25, "Charlotte, NC" };
        Person p2 { "Jaron", 26, "San Diego, CA" };

        std::cout << p1.getLoc() << ": " << p1.getName() << "\n";

        p2.printAssoc(p1);
    }
}

namespace ReturnClassInfo
{
    class Employee
    {
        private:
            std::string m_name { "Keyser Soze" };

        public:
            // use auto to deduce type
            const auto& getName() { return m_name; }
            void setName(std::string_view name) { m_name = name; }
    };

    void something()
    {
        Employee e {};
        std::cout << e.getName() << " doesn't exist.\n";

        e.setName("Roger Kint");
        std::cout << e.getName() << " doesn't exist.\n";
    }
}

namespace RValuePrac
{
    class Employee
    {
        private:
            std::string m_name { "Some broke bum" };
        
        public:
            Employee(std::string_view name = {})
            {
                if (!name.empty())
                    setName(name);
            }

            const std::string& getName() const { return m_name; }
            void setName(std::string_view name) { m_name = name; }
    };

    Employee createEmployee()
    {
        Employee e {};
        e.setName("Andrew Kohl (aka. The GOAT)");
        return e;
    }

    void something()
    {
        // need to assign the returned object immediately as rvalue will be deleted
        Employee andrew = createEmployee();
        std::cout << "Name:     " << andrew.getName() << "\n";

        // can change name as if own ref
        andrew.setName("Andrew Kohl (aka. The Mega GOAT)");
        std::cout << "Name:     " << andrew.getName() << "\n";

        // can get string if stored as object in memory
        std::string val { createEmployee().getName() };
        std::cout << val << "\n";

        const Employee second {};
        second.getName();
        std::cout << "Name:     " << second.getName() << "\n";
    }
}

namespace HandleInvariants
{
    class Employee
    {
        private:
            std::string m_name {};
            char m_firstInitial {};

        public:


            const std::string& getName() const { return m_name; }
            void setName(std::string_view name) 
            { 
                m_name = name; 
                m_firstInitial = name.front();
            }

            const char& getFirstInitial() const { return m_name.front(); }
    };

    void something()
    {
        Employee e {};
        e.setName("Bandrew");

        std::cout << "First initial:    " << e.getFirstInitial() << "\n";
    }
}

namespace UseNonMemberFunctionIfPossible
{
    class Yogurt
    {
        private:
            std::string m_flavor { "vanilla" };

        public:
            const std::string& getFlavor() const { return m_flavor; }
            void setFlavor(std::string_view flavor) { m_flavor = flavor; }
    };

    void printFlavor(const Yogurt& y)
    {
        std::cout << "The flavor of you ice cream is:   " << y.getFlavor() << "\n";
    }

    void something()
    {
        Yogurt yog {};
        yog.setFlavor("Great value light vanilla");

        printFlavor(yog);
    }
}

namespace ConstructorList
{
    class Foo
    {
        private:
            int m_x {};
            int m_y {};

        public:
            Foo(int x, int y)
                : m_x {x}, m_y {y}
            {
                std::cout << "Initialized:  " << m_x << ", " << m_y << "\n";
            }

            void print() const 
            {
                std::cout << m_x << ", " << m_y << "\n";
            }
    };

    void something()
    {
        Foo f {24, 25};
        f.print();
    }
}

// namespace HandleConstructorError
// {
//     class Fraction
//     {
//         private:
//             int m_numerator {};
//             int m_denominator {};

//             Fraction(int n, int d)
//                 : m_numerator { n }, m_denominator { d }
//             {
//                 std::cout << "Fraction initialized:     " << m_numerator << "/" << m_denominator << "\n";
//             }
        
//         public:
//             friend std::optional<Fraction> createFraction(int n, int d);    
//     }

//     friend std::optional<Fraction> createFraction(int n, int d)
//     {
//         if (d == 0)
//             return 0;
//         return Fraction {n, d};
//     }

//     void something()
//     {
//         auto f = createFraction(10, 45);
//     }
// }

