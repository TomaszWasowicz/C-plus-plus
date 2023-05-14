#include <cassert>
#include <iostream>

class Fraction
{
private:
	int method_numerator{};
	int method_denominator{};
public:
	Fraction()    //default constructor
	{
		method_numerator = 0;
		method_denominator = 1;
	}

	Fraction(int numerator, int denominator = 1)
	{
		assert(denominator != 0);
		method_numerator = numerator;
		method_denominator = denominator;
	}

	int getNumerator() { return method_numerator; }
	int getDenominator() { return method_denominator; }
	double getValue() { return static_cast<double>(method_denominator) / (method_denominator); }
};

int main()
{
	Fraction fiveThirds{ 20,4 };		// list initialization, calls Fraction(int, int)
	Fraction threeQuarters(40, 8);	//direct initialization, also calls Fraction (int,int)
	
	

	Fraction six = Fraction{ 7 };
	Fraction seven = 7;

	

	

	return 0;
}