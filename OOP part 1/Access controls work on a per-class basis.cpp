#include <iostream>

class DateClass // members are private by default
{
	int m_month{}; // private by default, can only be accessed by other members
	int m_day{}; // private by default, can only be accessed by other members
	int m_year{}; // private by default, can only be accessed by other members

public:
	void setDate(int month, int day, int year)
	{
		m_month = month;
		m_day = day;
		m_year = year;
	}

	void print()
	{
		std::cout << m_month << '/' << m_day << '/' << m_year;
	}

	// Note the addition of this function
	void copyFrom(const DateClass& d)
	{
		// Note that we can access the private members of d directly
		m_month = d.m_month;
		m_day = d.m_day;
		m_year = d.m_year;
	}
};

int main()
{
	DateClass date;
	date.setDate(10, 14, 2020); // okay, because setDate() is public

	DateClass copy{};
	copy.copyFrom(date); // okay, because copyFrom() is public
	copy.print();
	std::cout << '\n';

	return 0;
}