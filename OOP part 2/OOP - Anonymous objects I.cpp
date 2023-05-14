#include <iostream>

class Cents
{
private: 
	int m_cents{};

public:
	Cents(int cents)
		: m_cents{ cents }
	{

	}

	int getCents() const { return m_cents; }
};

void print(const Cents& cents)
{
	std::cout << cents.getCents() << " cents\n";
}

int main()
{
	Cents cents{ 6 };
	print(cents);

	print(Cents{ 7 });  // Anonymous cents value

	return 0;
}