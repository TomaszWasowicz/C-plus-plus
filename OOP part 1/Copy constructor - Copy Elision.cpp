#include <iostream>

class Something
{
	int m_x{};

public:
	Something(int x) : m_x{ x }
	{
		std::cout << "Normal constructor\n";
	}


	Something(const Something& s) : m_x{ s.m_x }
	{
		std::cout << "Copy constructor\n";
	}

	void print() const
	{
		std::cout << "Something(" << m_x << ")\n";
	}
};

int main()
{
	Something s{ Something {5} };
	// Something s { 5 }; // only invokes Something(int), no copy constructor

	//the compiler can optimize away the unnecessary copy and treat Something s{ Something{5} }; 
	// as if we had written Something s{ 5 } in the first place.
	//the process of doing so is called copy elision.
	// Copy elision is a compiler optimization technique 
	// that allows the compiler to remove unnecessary copying of objects.
	// In other words, in cases where the compiler would normally call a copy constructor, 
	// the compiler is free to rewrite the code to avoid the call to the copy constructor altogether.
	// When the compiler optimizes away a call to the copy constructor, 
	// we say the constructor has been elided.

	//Unlike other types of optimization, copy elision is exempt from the “as - if” rule.
	// That is, copy elision is allowed to elide the copy constructor 
	// even if the copy constructor has side effects(such as printing text to the console)!
	// This is why copy constructors should not have side effects other than copying
	// if the compiler elides the call to the copy constructor, 
	// the side effects won’t execute, and the observable behavior of the program will change!


	s.print();

	return 0;
}