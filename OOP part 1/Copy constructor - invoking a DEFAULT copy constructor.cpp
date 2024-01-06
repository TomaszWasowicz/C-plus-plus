#include <iostream>

class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	//Default constructor
	Fraction(int numerator=0, int denominator=1) : m_numerator{numerator}, m_denominator{denominator}{}

	void print()
	{
		std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
	}
};

int main()
{
	Fraction f{ 5,3 };
	Fraction fCopy{ f }; //invoking a default copy constructor

	f.print();
	fCopy.print();


	return 0;
}