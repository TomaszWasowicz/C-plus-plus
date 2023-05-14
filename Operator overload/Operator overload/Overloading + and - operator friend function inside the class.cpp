#include <iostream>

class Cents
{
private:
	int m_cents{};

public:
	Cents(int cents) : m_cents{cents}{}

	//add + Cents using a friend function
	// this function is not a member class, even though teh definition is inside the class

	friend Cents operator+(const Cents& c1, const Cents& c2)
	{
		//use the Cents constructor and operator + ( int, int )
		// I want to access m_cents directly because this is a friend function

		return Cents{ c1.m_cents + c2.m_cents };
	}

	friend Cents operator-(const Cents& c1, const Cents& c2)
	{
		return Cents{ c1.m_cents - c2.m_cents };
	}

	int getCents() const { return m_cents; }
};

int main()
{
	Cents cents1{ 6 };
	Cents cents2{ 2 };

	Cents centsSum{ cents1 + cents2 };
	Cents centsDiff{ cents1 - cents2 };

	std::cout << "I have " << centsSum.getCents() << " cents.\n";
	std::cout << "I have " << centsDiff.getCents() << " cents.\n";



	return 0;
}