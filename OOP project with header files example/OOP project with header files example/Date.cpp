#include "Date.h"

Date::Date(int year, int month, int day)			// Date constructor
{
	SetDate(year, month, day);
}

void Date::SetDate(int year, int month, int day)		// Date member function
{
	m_year = year;
	m_month = month;
	m_day = day;
}


