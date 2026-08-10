#pragma once

#include <iostream>
#include <cassert>
#include <cstddef>


namespace destructorPrac
{
    class IntArray
    {
        private:
            int* m_array{};
            int m_length{};

        public:
            IntArray(int length)
            {  
                assert(length > 0);

                m_array = new int[static_cast<std::size_t>(length)];
                m_length = length;
                
            }

            ~IntArray()
            {
                delete[] m_array;
            }

            void setValue(int val, int idx) { m_array[idx] = val; }
            int getValue(int index) { return m_array[index]; }

            int getLength() const { return m_length; }
    };


}