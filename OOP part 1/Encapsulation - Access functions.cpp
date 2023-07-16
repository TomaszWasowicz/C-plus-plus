#include <iostream>

class Date
{
private:
	int m_day;
	int m_month;
	int m_year;

public:
	int getDay() const { return m_day; }
	void setDay(int day) { m_day = day; }

	int getMonth() const { return m_month; }
	void setMonth(int month) { m_month = month; }

	int getYear() const { return m_year; }
	void setYear(int year) { m_year = year; }

};

int main()
{
	Date date{};
	date.setDay(15);
	date.setMonth(12);
	date.setYear(2023);


	std::cout << date.getDay() << '/' << date.getMonth() << '/' << date.getYear() << '\n';

	return 0;
}