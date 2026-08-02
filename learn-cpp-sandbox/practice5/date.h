#pragma once

class Date
{
    private:
        int m_year{};
        int m_month{};
        int m_day{};

    public:
        Date(int y, int m, int d);

        void print() const;

        int getYear() const { return m_year; }
        int getMonth() const { return m_month; }
        int getDay() const { return m_day; }
};