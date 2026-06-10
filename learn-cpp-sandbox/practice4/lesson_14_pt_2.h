#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>


namespace DefaultConstruct
{
    class Foo
    {
        private:
            int m_x {};
            int m_y {};
        
        public:
            Foo(int x=1, int y=1)
                : m_x{x}, m_y{y}
            {
                std::cout << "Foo constructed.\n"; 
            }

            void print()
            {
                std::cout << m_x << ", " << m_y << "\n";
            }
    };

    void something()
    {
        Foo f {};
        Foo f1 { 5, 6};

        f.print();
        f1.print();
    }
}

namespace DefaultConstructTwo
{
    class Foo
    {
        private:
            int m_x {};
            int m_y {};

        public:
            Foo() = default;

            Foo(int x, int y)
                : m_x { x }, m_y { y }
            {
                std::cout << "Instantiated\n";
            }

            void print()
            {
                std::cout << m_x << " " << m_y << "\n";
            }
    };

    void something()
    {
        Foo f1 {};
        Foo f2 { 54, 65};

        f1.print();
        f2.print();
    }
}

namespace DontUseDefault
{
    class Employee
    {
        private:
            std::string m_name {};
            int m_id {};

        public:
            Employee(std::string_view name, int id)
                : m_name { name }, m_id { id }
            {
                std::cout << m_name << " with ID -  " << m_id << "  - initialized.\n";
            }

            void print() const
            {
                std::cout << "Name:    " << m_name << '\n';
            }
    };

    void something()
    {
        Employee andrew { "Andrew", 43 };
        Employee alex { "Alex", 2 };

        andrew.print();
        alex.print();
    }
}

namespace DontRepeatYourself
{
    class Employee
    {
        private:
            std::string m_name {"???"};
            int m_age {0};
            bool m_is_manager {false};

            void printSuccess() const
            {
                std::cout << m_name << " created successfully.\n";
            }
        
        public:
            Employee(std::string_view name, int age)
                : m_name { name }, m_age { age }
            {
                printSuccess();
            }


            Employee(std::string_view name, int age, bool mgr)
                : m_name { name }, m_age { age }, m_is_manager { mgr }
            {
                printSuccess();
            }

            void print() const
            {
                std::cout << "\nName:         " << m_name << "\n";
                std::cout << "Age:          " << m_age << "\n";
                std::cout << "Manager:      " << m_is_manager << "\n";
            }
    };

    void something()
    {
        Employee andrew { "Andrew", 25};
        Employee ben { "Ben", 40, true };

        andrew.print();
        ben.print();
    }
}

namespace DelegateConstructors
{
    class Employee
    {
        private:
            std::string m_name {"???"};
            int m_age {};

            void printSuccess() const
            {
                std::cout << m_name << " created successfully.\n";
            }
        
        public:
            Employee(std::string_view name)
                : Employee { name, 0 }
            {
            }


            Employee(std::string_view name, int age)
                : m_name { name }, m_age { age }
            {
                printSuccess();
            }

            void print() const
            {
                std::cout << "\nName:         " << m_name << "\n";
                std::cout << "Age:          " << m_age << "\n";
            }
    };

    void something()
    {
        Employee andrew { "Andrew", 25};
        Employee ben { "Ben", 40 };

        andrew.print();
        ben.print();
    }
}

namespace UseDefaultArgs
{
    class Employee
    {
        private:
            std::string m_name {"???"};
            int m_age {0};

            void printSuccess() const
            {
                std::cout << m_name << " created successfully.\n";
            }
        
        public:
            Employee(std::string_view name, int age = 0)
                : m_name { name }, m_age { age }
            {
                printSuccess();
            }

            void print() const
            {
                std::cout << "\nName:         " << m_name << "\n";
                std::cout << "Age:          " << m_age << "\n";
            }
    };

    void something()
    {
        Employee andrew { "Andrew"};
        Employee ben { "Ben", 40 };

        andrew.print();
        ben.print();
    }
}

namespace AvoidMultDefaults
{
    class Employee
    {
        private:

            static constexpr int default_age {0};

            std::string m_name {"???"};
            int m_age { default_age };

            void printSuccess() const
            {
                std::cout << m_name << " created successfully.\n";
            }
        
        public:
            Employee(std::string_view name, int age = default_age)
                : m_name { name }, m_age { age }
            {
                printSuccess();
            }

            void print() const
            {
                std::cout << "\nName:         " << m_name << "\n";
                std::cout << "Age:          " << m_age << "\n";
            }
    };

    void something()
    {
        Employee andrew { "Andrew"};
        Employee ben { "Ben", 40 };

        andrew.print();
        ben.print();
    }
}

namespace BallQuiz
{
    class Ball
    {
        private:
            static constexpr std::string_view default_color { "blue" };
            static constexpr double default_radius { 10.0 };

            std::string m_color { default_color };
            double m_radius { default_radius };

            void printSuccess() const
            {
                std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
            }

        public:
            Ball(std::string_view color = default_color, double radius = default_radius)
                : m_color { color }, m_radius { radius }
            {
                printSuccess();
            }
    };

    void something()
    {
        Ball def{};
        Ball blue{ "blue" };
        Ball twenty{ "blue", 20.0 };
        Ball blueTwenty{ "blue", 20.0 };

    }

}

namespace TemporaryObjects
{
    class IntPair
    {
        private:
            int m_x {};
            int m_y {};
        
        public:
            IntPair(int x, int y)
                : m_x {x}, m_y {y}
            {}

            int x() const { return m_x; }
            int y() const { return m_y; }
    };

    void print(IntPair p)
    {
        std::cout << "(" << p.x() << ", " << p.y() << ")\n";
    }

    void something()
    {
        // Case 1: Pass variable
        IntPair p { 3, 4 };
        print(p);

        // Case 2: Construct Temporary IntPair and pass to function
        print(IntPair { 5, 6 });

        // Case 3: Implcityly convert 7, 8 to a tempoarry IntPair and pass to function
        print({ 7, 8 });
    }
}

namespace CopyConstructor
{
    class Fraction
    {
        private:
            int m_numerator {0};
            int m_denominator {1};

        public:
            Fraction(int n, int d)
                : m_numerator{n}, m_denominator{d}
            {}

            // Copy constructor - automatically there behind the scenes though 
            // Best practice: just stick with implicit copy constructor
            Fraction(const Fraction& f)
            : m_numerator {f.m_numerator}
            , m_denominator {f.m_denominator}
            {
                std::cout << "Copy constructor ran.\n";
            }

        void print() const { std::cout << m_numerator << "/" << m_denominator << "\n"; }
    };

    void something()
    {
        Fraction f { 54, 78};
        Fraction fcopy { f };

        f.print();
        fcopy.print();
    }
}

namespace CopyAutomaticWhenPassedByValue
{
    class Fraction
    {
        int m_n {};
        int m_d {};

        public:
            Fraction(int x, int y)
                : m_n{x}, m_d{y}
            {}

            Fraction(const Fraction& f)
            : m_n{f.m_n}, m_d{f.m_d}
            {
                std::cout << "Copied\n";
            }

            void print() const { std::cout << m_n << "/" << m_d << "\n"; }
    };

    void printFraction(Fraction f)
    {
        f.print();
    }

    void something()
    {
        Fraction f { 1, 4 };
        // This will create a copy inherently through passing by value
        printFraction(f);
    }
}

namespace ReturnByValue
{
    class Fraction
    {
        int m_n {};
        int m_d {};

        public:
            Fraction(int x, int y)
                : m_n{x}, m_d{y}
            {}

            Fraction(const Fraction& f)
            : m_n{f.m_n}, m_d{f.m_d}
            {
                std::cout << "Copied\n";
            }

            void print() const { std::cout << m_n << "/" << m_d << "\n"; }
    };

    void printFraction(Fraction f)
    {
        f.print();
    }

    Fraction generateFraction(int n, int d)
    {
        Fraction f{n, d};
        return f;
    }

    void something()
    {
        Fraction f2 { generateFraction(1,2) };
        // This will create a copy inherently through passing by value
        printFraction(f2);
    }
}

namespace ConvertingConstructors
{
    class Foo
    {
        private:
            int m_x {};
        
        public:
            Foo(int x)
                : m_x{x}
            {}

            int getX() const { return m_x; }

    };

    void printFoo(Foo f)
    {
        std::cout << f.getX() << "\n";
    }

    void something()
    {
        printFoo(5);
    }
}

namespace Explicit
{
    class Dollars
    {
        private:
            int m_dollars {};

        public:
            explicit Dollars(int d)
                : m_dollars{d}
            {   
            }

            int getDollars() const { return m_dollars; }
    };

    void print(Dollars d)
    {
        std::cout << "$" << d.getDollars() << "\n";
    }

    void something()
    {
        // Need to make at least temporary class - cannot just submit an integer now
        print(Dollars{5});
    }
}

namespace ConstexprClass
{
    class Pair
    {
        private:
            int m_x {};
            int m_y {};

        public:
            constexpr Pair(int x, int y)
                : m_x {x}, m_y {y}
            {
            }

            constexpr int greater() const 
            {
                return (m_x > m_y) ? m_x : m_y;
            }
    };

    void something()
    {
        constexpr Pair p { 1, 2};

        std::cout << p.greater() << "\n";
    }
}

namespace QuizQ1
{
    class Point2D
    {
        private:
            double m_x {};
            double m_y {};

        public:
            explicit Point2D(double x=0.0, double y=0.0)
                : m_x{x}, m_y{y}
            {}

            void print() const
            {
                std::cout << "Point2D(" << m_x << ", " << m_y << ")\n";
            }

            double getX() const { return m_x; }
            double getY() const { return m_y; }

            double distanceTo(const Point2D& p) const
            {
                double distance = std::sqrt((m_x - p.getX())*(m_x - p.getX()) + (m_y - p.getY())*(m_y - p.getY()));
                return distance;
            }
    };

    void something()
    {
        const Point2D first {};
        const Point2D second { 3.0, 4.0};

        first.print();
        second.print();

        std::cout << first.distanceTo(second) << "\n";;
    }
}