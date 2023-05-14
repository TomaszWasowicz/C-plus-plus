#include <iostream>

class Cents
{
private:
	int m_cents{};

public:
	Cents(int cents) : m_cents{cents}{}

	int getCents() const{ return m_cents; }
};


// this function is not a member function!
Cents operator+ (const Cents& c1, const Cents& c2)
{

	//use the Cents constructor and operator+(int, int)
	//I don't need direct access to private members here

	return Cents{ c1.getCents() + c2.getCents()};
}

int main()
{
	Cents cents1{ 6 };
	Cents cents2{ 8 };
	Cents centsSum{ cents1 + cents2 };
	std::cout << "I have " << centsSum.getCents() << " cents.\n";


	return 0;
}