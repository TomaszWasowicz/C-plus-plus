#include <iostream>

class Cents
{
private:
	int m_cents{};

public:
	Cents(int cents) : m_cents{ cents } {}

	//add + an - Cents using a friend fucntion

	friend Cents operator+(const Cents& c1, const Cents& c2);

	friend Cents operator-(const Cents& c1, const Cents& c2);

	int getCents() const { return m_cents; }
};

Cents operator+(const Cents& c1, const Cents& c2)
{
	return Cents{ c1.m_cents + c2.m_cents };
}

Cents operator-(const Cents& c1, const Cents& c2)
{
	return Cents(c1.m_cents - c2.m_cents);
}

int main()
{
	Cents cents1{ 6 };
	Cents cents2{ 8 };

	Cents centsSum{ cents1 + cents2 };
	std::cout << "I have " << centsSum.getCents() << " cents.\n";

	Cents centsSub{ cents1 - cents2 };
	std::cout << "I have " << centsSub.getCents() << " cents.\n";


	return 0;
}