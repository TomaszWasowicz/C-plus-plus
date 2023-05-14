#include <iostream>

class Date
{
private:
	int m_month;
	int m_day;
	int m_year;

public:
	int getMonth() { return m_month; }
	void setMonth(int month) { m_month = month; }
		
	int getDay() { return m_day; }
	void setDay(int day) { m_day = day; }

	int getYear() { return m_year; }
	void setYear(int year) { m_year = year; }
};

int main()
{



	return 0;
}