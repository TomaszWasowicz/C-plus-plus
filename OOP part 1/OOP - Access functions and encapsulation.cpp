#include< iostream>

class Date
{
private:
	int m_month{};
	int m_day{};
	int m_year{};

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

	int getMonth(){return m_month;}				//return by avalue or by const reference
	void setMonth(int month){m_month = month;}

	int getDay(){return m_day;}
	void setDay(int day){m_day = day;}

	int getYear(){return m_year;}
	void setYear(int year){m_year = year;}
};


int main()
{
	Date date;
	Date date2;

	date.setDate(12, 5, 2022);
	date2.setDate(30, 6, 1999);

	date2.setYear(2033);
	date2.getYear();

	date.print();
	date2.print();



	return 0;

}
