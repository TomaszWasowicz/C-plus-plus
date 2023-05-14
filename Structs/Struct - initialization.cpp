#include <iostream>

struct Fraction
{
	int numerator{}; // we should use { 0 } here, but for the sake of example we'll use value initialization instead
	int denominator{};
	short passingnumber{};
	double percentage{};
};

void printFraction(const Fraction& fraction )
{
	std::cout << fraction.numerator << '\n';
	std::cout << fraction.denominator << '\n';
}

int main()
{
	Fraction fraction1{ 2,3 };
	Fraction fraction2{};       // f2.numerator value initialized to 0, f2.denominator defaulted to 1
	Fraction fraction3{ 6 };    // f3.numerator initialized to 6, f3.denominator defaulted to 1
	Fraction fraction4{ 5, 8 }; // f4.numerator initialized to 5, f4.denominator initialized to 8


	printFraction(fraction4);

	std::cout << "The byte size of is " << sizeof(Fraction) << '\n';

	return 0;
}

