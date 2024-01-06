#include <iostream>

class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	//Default constructor
	Fraction(int numerator = 0, int denominator = 1) : m_numerator{ numerator }, m_denominator{ denominator } 
	{
		std::cout << "Constructor called\n";
	}

	//Fraction(const Fraction& fraction) = default;   //expplicitly request a copy constructor

	//Fraction(const Fraction& fraction) = delete;		// Delete the copy constructor so no copies can be made

	//Copy Constructor
	// Initialize member using the corresponding member of the parameter
	Fraction(const Fraction& fraction) : m_numerator{ fraction.m_numerator }, m_denominator{ fraction.m_denominator }
	{
		std::cout << "Copy constructor called\n";
	}
	

	void print() const
	{
		std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
	}
};

//f is pass by value
void printFraction(Fraction f)
{
	f.print();
}

Fraction generateFraction(int n, int d)
{
	Fraction f{ n , d };
	return f;
}


int main()
{
	Fraction f{ 5,3 };

	printFraction(f);			// f is copied into the function parameter using a copy constructor

	Fraction f2{ generateFraction(1,2) };   //Fraction is returned using copy constructor

	printFraction(f2);        //f is copied into the function parameter using a copy constructor

	Fraction fCopy{ f }; //invoking a default copy constructor

	f.print();
	fCopy.print();


	return 0;
}