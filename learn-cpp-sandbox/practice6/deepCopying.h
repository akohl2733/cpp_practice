#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <string_view>
#include <cassert>


namespace assignmentOverload
{
    class Fraction
    {
        private:
            int m_num {0};
            int m_den {1};

        public:
            Fraction(int num=0, int den=1)
                : m_num { num }, m_den{ den }
            {
                assert(den!=0);
            }

            Fraction(const Fraction& copy)
                : m_num { copy.m_num }, m_den { copy.m_den }
            {
                std::cout << "Copy constructor called\n";
            }

            // overloaded assignment
            Fraction& operator=(const Fraction& fraction);

            friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
    };

    std::ostream& operator<<(std::ostream& out, const Fraction& f1)
    {
        out << f1.m_num << "/" << f1.m_den << "\n";
        return out;
    }

    Fraction& Fraction::operator=(const Fraction& fraction)
    {
        m_num = fraction.m_num;
        m_den = fraction.m_den;

        return *this;
    }

    void doSomething()
    {
        Fraction fiveThirds { 5, 3};
        Fraction f;
        f = fiveThirds;
        std::cout << f;
    }
}

namespace defaultCopyConstructor
{
    class Fraction
    {
        private:
            int m_num{0};
            int m_den{1};

        public:
            Fraction(int num, int den)
                : m_num{num}, m_den{den}
            {
                assert(den!=0);
            }

            // possible implementation of implicit copy constructor
            Fraction(const Fraction& f)
                : m_num{f.m_num}, m_den{f.m_den}
            {
            }

            // possible implementation of implicit assignment operator
            Fraction& operator=(const Fraction& fraction)
            {
                if (this == &fraction)
                    return *this;

                m_num = fraction.m_num;
                m_den = fraction.m_den;

                return *this;
            }

            friend std::ostream& operator<<(std::ostream& out, const Fraction& f1)
            {
                out << f1.m_num << "/" << f1.m_den << "\n";
                return out;
            }
    };
}

namespace deepCopy
{
    class MyString
    {
    private:
        char* m_data{};
        int m_length{};

    public:
        MyString(const char* source = "" )
        {
            assert(source); // make sure source isn't a null string

            // Find the length of the string
            // Plus one character for a terminator
            m_length = std::strlen(source) + 1;

            // Allocate a buffer equal to this length
            m_data = new char[m_length];

            // Copy the parameter string into our internal buffer
            for (int i{ 0 }; i < m_length; ++i)
                m_data[i] = source[i];
        }

        ~MyString() // destructor
        {
            // We need to deallocate our string
            delete[] m_data;
        }

        void deepCopy(const MyString& source);

        char* getString() { return m_data; }
        int getLength() { return m_length; }
    };

    void MyString::deepCopy(const MyString& source)
    {
        delete[] m_data;

        m_length = source.m_length;

        if (source.m_length)
        {
            m_data = new char[m_length];

            for (int i{0}; i < m_length; ++i)
                m_data[i] = source.m_data[i];
        }
        else 
            m_data = nullptr;
    }

    MyString::MyString(const MyString& source)
    {
        deepCopy(source);
    }

    MyString& MyString::operator=(const MyString& source)
    {
        if (this != &source)
        {
            deepCopy(source);
        }

        return *this;
    }
}