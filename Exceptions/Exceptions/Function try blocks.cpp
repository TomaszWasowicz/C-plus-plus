#include <iostream>

class A
{
private:
	int m_x;
public:
	A(int x) : m_x{ x }
	{
		if (x <= 0)
			throw 1; // Exception thrown here
	}
};

class B : public A
{
public:
	B(int x) try : A{ x } // addition of try keyword here
	{
	}
	catch (...) //  this is at same level of indentation as the function itself
	{
		// Exceptions from member initializer list or
		// from constructor body are caught here

		std::cerr << "Exception caught\n";

		throw; // rethrow the existing exception
	}
};

int main()
{
	try
	{
		B b{ 0 };
	}
	catch (int)
	{
		std::cout << "Oops\n";
	}
}