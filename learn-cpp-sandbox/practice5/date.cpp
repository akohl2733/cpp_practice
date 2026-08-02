#include "date.h"
#include <iostream>

Date::Date(int y, int m, int d)
    : m_year{y}, m_month{m}, m_day{d}
    {
    }

void Date::print() const { std::cout << this->m_year << "\n"; }