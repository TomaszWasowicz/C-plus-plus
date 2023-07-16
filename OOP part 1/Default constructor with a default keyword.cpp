#include <iostream>

class Date
{
private:
	int m_day{1};
	int m_month{ 1 };
	int m_year{ 1 };

public:

	Date() = default;

	Date(int day, int month, int year)
	{
		m_day = day;
		m_month = month;
		m_year = year;
	}


	bool operator==(const Date& other) const
	{
		return false;
	}
};

int main()
{
	Date date{};  //initialized on 1,1,1
	Date today{ 2023, 06, 18 };



	return 0;
}