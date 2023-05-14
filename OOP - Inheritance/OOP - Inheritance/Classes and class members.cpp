#include <iostream>

class Date
{
private:
	int m_year{};
	int m_month{};
	int m_day{};

public:

	void setDate(int year, int month, int day)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}

	void print() const
	{
		std::cout << m_year << '-' << m_month << '-' << m_day << '\n';
	}
};

int main()
{

	Date date1;
	Date date2;

	date2.setDate(2024, 11, 5);

	date1.print();   // bez podanie argumentow wydrukowane bedzie "0-0-0"
	date2.print();

	//date1.m_day = 16;    // nie mozw byc wykonane poniewaz main() nie ma dostepu do m_day
	
	return 0;
}