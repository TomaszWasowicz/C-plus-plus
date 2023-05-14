class Date
{
private:
	int m_year{ 1900 };
	int m_month{ 12 };
	int m_day{ 1 };

public:
	Date(int year, int month, int day) //normal noon-default constructor
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}

	Date() = default;   // BARDZO WAZNE, bez tego nie bedzie defaultowego constructora

	// no implicit constructor provided because we have alread defined our own constructor
		
};

int main() {

	Date date{};  //wywolany jest construktor ze zmiennymi 1900,12,1

	// potential error - if there's no default constructor then
	//you can't instantiate object becasue constructor doesn't exit and the compiler won't generate one


	Date date2{ 2030, 14, 4 };

	return 0;
}