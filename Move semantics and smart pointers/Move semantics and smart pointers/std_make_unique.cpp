#include <memory>
#include <iostream>

class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1)
	{
		out << f1.m_numerator << '/' << f1.m_denominator;
		return out;
	}
};

int main()
{
	//Single dynamically allocated Fraction object (3,5)
	//automatic type deduction

	auto f1{ std::make_unique<Fraction>(3,5) };
	std::cout << *f1 << '\n';

	//dynamically allocated array of Fraction objects, of length 4

	auto f2{ std::make_unique<Fraction[]>(4) };

	std::cout << f2[0] << '\n';


	//some_function(std::unique_ptr<T>(new T), function_that_can_throw_exception());
	
	//The compiler is given a lot of flexibility in terms of how it handles this call.
	// It could create a new T, then call function_that_can_throw_exception(), 
	// then create the std::unique_ptr that manages the dynamically allocated T.
	// If function_that_can_throw_exception() throws an exception, 
	// then the T that was allocated will not be deallocated, 
	// because the smart pointer to do the deallocation hasn’t been created yet.
	// This leads to T being leaked. 
	
	//std::make_unique() doesn’t suffer from this problem because the creation 
	// of the object T and the creation of the std::unique_ptr happen inside 
	// the std::make_unique() function, where there’s no ambiguity about 
	// order of execution.
	//This issue was fixed in C++17, as evaluation of function arguments 
	// can no longer be interleaved.


	return 0;
}