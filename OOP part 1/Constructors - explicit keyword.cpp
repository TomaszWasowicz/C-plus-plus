#include <iostream>

class Dollars
{
private:
	int m_dollars{};

public:
	//explicit - keyword to tell the compiler that a constructor 
	// should not be used as a converting constructor.

	//here: if our print(Dollars) function could only be called with a Dollars object, 
	// not any value that can be implicitly converted to a Dollars 
	// (especially a fundamental type like int) 

	explicit Dollars(int d) : m_dollars{ d }
	{

	}

	int getDollars() const
	{
		return m_dollars;
	}
};

void print(Dollars d)
{
	std::cout << "$" << d.getDollars() << std::endl;
}

int main()
{
	//print(5);          //compilation error because Dollars(int) is explicit

	print(Dollars(4));		// pass the the created constructor to a function
	print(Dollars{ 2 });

	//an explicit constructor can still be used for direct and direct list initialization

	Dollars d1(5);   
	Dollars d2{ 6 };

	return 0;
}