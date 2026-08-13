#pragma once
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <utility>

namespace rValReference
{
    class Fraction
    {
        private:
            int m_numerator { 0 };
            int m_denominator { 1 };

        public:
            Fraction(int num, int den)
                : m_numerator{num}, m_denominator{den}
                {
                }

            friend std::ostream& operator<<(std::ostream& out, const Fraction& f1)
            {
                out << f1.m_numerator << "/" << f1.m_denominator;
                return out;
            }
    };

    void doSomething()
    {
        auto&& rref{ Fraction{ 3, 5 }};

        std::cout << rref << '\n';
    }
}

namespace rValueFunctionParams
{
    void fun(const int& lref)
    {
        std::cout << "l-value reference to const: " << lref << '\n';
    }

    void fun(const int&& rref) {
        std::cout << "r-value reference to const: " << rref << "\n";
    }

    void doSomething()
    {
        int x{5};
        fun(x);
        fun(4);
    }
}

namespace autoPtrPractice // random
{
    template<typename T>
    class Auto_ptr3
    {
            T* m_ptr{};

        public:
            Auto_ptr3(T* ptr = nullptr)
                : m_ptr{ptr}
            {
            }

            ~Auto_ptr3()
            {
                delete m_ptr;
            }

            // Copy constructor
            // Do deep copy of a.m_ptr to m_ptr
            Auto_ptr3(const Auto_ptr3& a)
            {
                m_ptr = new T;
                *m_ptr = *a.m_ptr;
            }

            // Copy assignment
            // Do deep copy of a.m_ptr to m_ptr
            Auto_ptr3& operator=(const Auto_ptr3& a)
            {
                // check self-assignment
                if (&a == this)
                    return *this;
                
                // release any resource we are holding
                delete m_ptr;

                // copy the resource
                m_ptr = new T;
                *m_ptr = *a.m_ptr;

                return *this;
            }

            T& operator*() const { return *m_ptr; }
            T* operator->() const { return m_ptr; }
            bool isNull() const { return m_ptr==nullptr; }
    };

    class Resource
    {
        public:
            Resource() { std::cout << "Resource acquired\n"; }
            ~Resource() { std::cout << "Resource destroyed\n"; }
    };

    Auto_ptr3<Resource> generateResource()
    {
        Auto_ptr3<Resource> res { new Resource };
        return res;
    }

    void doSomething()
    {
        Auto_ptr3<Resource> mainres;
        mainres = generateResource();
    }
}

namespace move
{
    template<typename T>
    class Auto_ptr4
    {
            T* m_ptr{};

        public:
            Auto_ptr4(T* ptr = nullptr)
                : m_ptr{ptr}
            {
            }

            ~Auto_ptr4()
            {
                delete m_ptr;
            }

            // Copy constructor
            // Do deep copy of a.m_ptr to m_ptr
            Auto_ptr4(const Auto_ptr4& a)
            {
                m_ptr = new T;
                *m_ptr = *a.m_ptr;
            }

            // move constructor
            // transfer ownership of a.m_ptr to m_ptr
            Auto_ptr4(Auto_ptr4&& a) noexcept
                : m_ptr{ a.m_ptr }
            {
                a.m_ptr = nullptr;
            }

            // Copy assignment
            // Do deep copy of a.m_ptr to m_ptr
            Auto_ptr4& operator=(const Auto_ptr4& a)
            {
                // check self-assignment
                if (&a == this)
                    return *this;
                
                // release any resource we are holding
                delete m_ptr;

                // copy the resource
                m_ptr = new T;
                *m_ptr = *a.m_ptr;

                return *this;
            }

            // move assignment
            // transfer ownership of a.m_ptr to m_ptr
            Auto_ptr4& operator=(Auto_ptr4&& a) noexcept
            {
                if (&a == this)
                    return *this;

                delete m_ptr;

                m_ptr = a.m_ptr;
                a.m_ptr = nullptr;

                return *this;
            }

            T& operator*() const { return *m_ptr; }
            T* operator->() const { return m_ptr; }
            bool isNull() const { return m_ptr==nullptr; }
    };

    class Resource
    {
        public:
            Resource() { std::cout << "Resource acquired\n"; }
            ~Resource() { std::cout << "Resource destroyed\n"; }
    };

    Auto_ptr4<Resource> generateResource()
    {
        Auto_ptr4<Resource> res { new Resource };
        return res;
    }

    void doSomething()
    {
        Auto_ptr4<Resource> mainres;
        mainres = generateResource();
    }
}

namespace copyBad
{
    std::vector<int> generate()
    {
        std::vector<int> arr1 { 1, 2, 3, 4, 5 };
        return arr1;
    }

    void doSomething()
    {
        std::vector<int> arr2 {generate()};

        arr2[0] = 7;

        std::cout << arr2[0] << "\n";
    }
}

namespace moveSemantics
{
    std::vector<int> doSomething(std::vector<int> v2)
    {
        std::vector<int> v3 { v2[0] + v2[0] };
        return v3;
    }

    void something()
    {
        std::vector<int> v1 { 5 };
        std::cout << doSomething(v1)[0] << "\n";

        std::cout << v1[0] << '\n';
    }
}

namespace moreMove
{
    template <typename T>
    class DynamicArray
    {
        private:
            T* m_array {};
            int m_length {};
        
        public:
            DynamicArray(int length)
                : m_length{length}
            {
            }

            ~DynamicArray()
            {
                delete[] m_array;
            }

            // copy constructor
            DynamicArray(const DynamicArray &arr) = delete;
        
            // copy assignment
            DynamicArray& operator=(const DynamicArray &arr) = delete;

            // move constructor
            DynamicArray(DynamicArray &&arr) noexcept
                : m_array{arr.m_array}, m_length{arr.m_length}
            {
                arr.m_length = 0;
                arr.m_array = nullptr;
            }

            // move assignment
            DynamicArray& operator=(DynamicArray &&arr) noexcept
            {
                if (&arr == this)
                    return *this;

                delete[] m_array;

                m_length = arr.m_length;
                m_array = arr.m_array;
                arr.m_length = 0;
                arr.m_array = nullptr;

                return *this;
            }

            int getLength() const { return m_length; }
            T& operator[](int index) { return m_array[index]; }
            const T& operator[](int index) const { return m_array[index]; }
    };


}

namespace usingMove
{
    template <typename T>
    void mySwapMove(T& a, T& b)
    {
        T tmp { std::move(a) };
        a = std::move(b);
        b = std::move(tmp);
    }

    void doSomething()
    {
        std::string x{ "abc" };
        std::string y{ "de" };

        std::cout << "x: " << x << "\n";
        std::cout << "y: " << y << "\n";

        mySwapMove(x, y);

        std::cout << "x: " << x << "\n";
        std::cout << "y: " << y << "\n";

    }
}