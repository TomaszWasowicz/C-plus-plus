#include <iostream>

class Cents
{
private:
	int m_cents{};

public:
	explicit(false) Cents(int cents): m_cents{cents}{}

	int getCents() const { return m_cents; }
};

Cents add(const Cents& c1, const Cents& c2)
{
	return { c1.getCents() + c2.getCents() };
}

int main()
{
	//Cents cents1{ 6 };
	//Cents cents2{ 8 };
	//std::cout << "I have " << add(cents1, cents2).getCents() << " cents.\n";


	//full anonymous object
	std::cout << "I have " << add(Cents{6}, Cents{8}).getCents() << " cents.\n";

	return 0;
}