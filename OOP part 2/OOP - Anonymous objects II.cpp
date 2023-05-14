#include <iostream>

class Cents
{
private:
	int m_cents{};

public:
	Cents(int cents) : m_cents{ cents }
	{

	}

	int getCents() const { return m_cents; }
};

Cents add(const Cents& c1, const Cents& c2)
{
	Cents sum{ c1.getCents() + c2.getCents() };
	return sum;
}

int main()
{
	Cents cents1{ 6 };
	Cents cents2{ 8 };
	Cents sum{ add(cents1, cents2) };
	std::cout << "I have " << sum.getCents() << " cents.\n";

	return 0;
}