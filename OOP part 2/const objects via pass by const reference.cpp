#include <iostream>

class Date
{
private:
    int m_year{};
    int m_month{};
    int m_day{};

public:
    Date(int year, int month, int day)
    {
        setDate(year, month, day);
    }

    void setDate(int year, int month, int day)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }

    int getYear() const{ return m_year; }
    int getMonth() const{ return m_month; }
    int getDay() const { return m_day; }
};

// note: We're passing date by const reference here to avoid making a copy of date
// CONST MEMBERS CANNOT RETURN NON CONST REFERENCE TO MEMBERS
void printDate(const Date& date)
{
    std::cout << date.getYear() << '/' << date.getMonth() << '/' << date.getDay() << '\n';
}

int main()
{
    Date date{ 2016, 10, 16 };
    printDate(date);

    return 0;
}