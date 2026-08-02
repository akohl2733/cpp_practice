#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace thisPrac
{
    class Simple
    {
        private:
            int m_value{};
        
        public:
            
            Simple& add(int i) { this->m_value += i; return *this; }
            Simple& sub(int i) { this->m_value -= i; return *this; }
            Simple& mult(int i) { this->m_value *= i; return *this; }
            
            
            int getValue() const { return m_value; }
    };

    void doSomething()
    {
        Simple s{};
        
        s.add(10).sub(6).mult(86);
        int ans = s.getValue();
        std::cout << ans << "\n";
    }
}

namespace ConstructorDef
{
    class Date
    {
        private:
            int m_year{};
            int m_month{};
            int m_day{};

        public:
            Date(int year, int month, int day);

            void print() const; // print function declaration

            int getYear() const { return m_year; }
            int getMonth() const { return m_month; }
            int getDay() const  { return m_day; }
    };

    Date::Date(int year, int month, int day)
        : m_year(year), m_month(month), m_day(day)
    {
    }

    void Date::print() const { std::cout << m_month << "\\" << m_day << "\\" << m_year << "\n"; }

    void doSomething()
    {
        Date d {2026, 10, 10};
        d.print();
    }
}

namespace NestedStuff
{
    class Fruit
    {
        public:
            enum Type
            {
                apple,
                banana,
                cherry
            };

        private:
            Type m_type{};
            int m_percentEaten{0};

        public:
            Fruit(Type type)
                : m_type{type}
            {
            }

            Type getType() const { return this->m_type; }
            int getPE() const { return this->m_percentEaten; }

            bool isCherry() const { return m_type == cherry; }
    };

    std::string_view getStr(bool b)
    {
        if (b == 0)
            return "No.";
        else
            return "Yes.";
    }

    void doSomething()
    {
        Fruit f{ Fruit::cherry };
        bool cherry = f.isCherry();

        std::string_view s = getStr(cherry);

        std::cout << "Is this cherry? " << s << "\n";
    }
}

namespace EmployeePrint
{
    class Employee
    {
        using IDType = int;

        public:
            class Printer
            {
                public:
                    void print(const Employee& e) const
                    {
                        std::cout << e.m_name << " has an ID of " << e.m_id << "\n";
                    }
            };
        
        private:
            std::string m_name{};
            IDType m_id{};
            double m_wage{};

        public:
            Employee(std::string_view name, IDType id, double wage)
                : m_name{name}, m_id{id}, m_wage{wage}
            {
            }

    };

    void doSomething()
    {
        const Employee john{ "John", 1, 50000 };
        const Employee::Printer p{};
        p.print(john);
    }
}

namespace DestructorIntro
{
    class Simple
    {
        private:
            int m_id{};

        public:
            Simple(int id)
                : m_id{id}
            {
                std::cout << "Creating Simple " << m_id << "\n";
            }

            ~Simple()
            {
                std::cout << "Destroying this Simple object #" << m_id << "\n";
            }

            int getId() const { return m_id; }
    };

    void doSomething()
    {
        Simple s1 {1};
        {
            Simple s2 {2};
        }
    }
}

namespace TypeTemplateMember
{
    template <typename T>
    class Pair
    {
        private:
            T m_first{};
            T m_second{};

        public:
            Pair(const T& first, const T& second)
                : m_first{first}, m_second{second}
            {
            }

            bool isEqual(const Pair<T>& pair);
    };

    template <typename T>
    bool Pair<T>::isEqual(const Pair<T>& pair)
    {
        return m_first == pair.m_first && m_second == pair.m_second;
    }

    void doSomething()
    {
        Pair<int> p1 { 5, 6 };
    }
}

namespace FriendPrac
{
    class Accumulator
    {
        private:
            int m_value {0};

        public:
            void add(int val) { m_value += val; }

            friend void print(const Accumulator& acc);
    };

    void print(const Accumulator& acc) { std::cout << acc.m_value; }
}

namespace Telemetry
{
    class SensorData
    {
        private:
            int m_x{};
            int m_y{};
            int m_z{};
            double m_velocity{};

        public:
            SensorData(int x, int y, int z, double v);

            int getX() const { return m_x; }
            int getY() const { return m_y; }
            int getZ() const { return m_z; }
            double getVelocity() const { return m_velocity; }
    };

    SensorData::SensorData(int x, int y, int z, double velocity)
        : m_x{x}, m_y{y}, m_z{z}, m_velocity{velocity}
    {}
}