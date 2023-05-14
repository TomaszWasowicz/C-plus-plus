#include <iostream>

class Date
{
private:
    int m_month{};
    int m_day{};
    int m_year{};

public:

    Date() //: m_month{0}, m_day{0}, m_year{0}         //lista inicjalizacyjna
    {
        m_month = 0;
        m_day = 0;
        m_year = 0;
    }

    const int& getMonth() const { return m_month; } // getter for month
    void setMonth(int month) { m_month = month; } // setter for month

    const int& getDay() const { return m_day; } // getter for day
    void setDay(int day) { m_day = day; } // setter for day

    const int& getYear() const { return m_year; } // getter for year
    void setYear(int year) { m_year = year; } // setter for year


};
int main()
{

    Date today; //1st object
    Date today2; //2nd object

    today.setMonth(7);
    today.setDay(30);
    today.setYear(2020);

    today2.setMonth(15);

    std::cout << today2.getMonth() << '\n';

    std::cout << today.getMonth() << '/' << today.getDay() << '/' << today.getYear() << '\n';


    return 0;
}