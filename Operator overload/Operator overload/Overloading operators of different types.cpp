#include <iostream>

class Cents
{
private:
	int m_cents{};

public:
	Cents(int cents): m_cents{cents}{}

	//add Cents + int using a friend function
	friend Cents operator+(const Cents& c1, int value);

	//add int + Cents using a friend function
	friend Cents operator+(int value, const Cents& c1);

	int getCents() const { return m_cents; }
};

// this function is not a member function !

Cents operator+(const Cents& c1, int value)
{
	//use the Cents constructor and operator+(int, int)
	//we can access m_cents directly because this is a friend function
	return { c1.m_cents + value };
}

//this function is not a member function!

Cents operator+(int value, const Cents& c1)
{
	//use the Cents constructor and operator+(int, int)
	//we can access m_cents directly because this is a friend function
	return{ value + c1.m_cents };
}

int main()
{
	Cents c1{ Cents{4} + 6 };
	Cents c2{ 9 + Cents{7} };

	std::cout << "I have " << c1.getCents() << " cents.\n";
	std::cout << "I have " << c2.getCents() << " cents.\n";



	return 0;
}
