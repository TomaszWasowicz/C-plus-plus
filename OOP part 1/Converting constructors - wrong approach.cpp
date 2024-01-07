#include <iostream>

class Dollars
{
private:
	int m_dollars{};

public:
	Dollars(int d) : m_dollars{ d }
	{

	}

	int getDollars() const
	{
		return m_dollars;
	}
};

void print(Dollars d)   
// it would be better to pass by const reference like:   void print( const Dollars& d)
{
	std::cout << "$" << d.getDollars();
}

int main()
{
	print(5);

	//It would be better if print(Dollars) function 
	// could only be called with a Dollars object, 
	// not any value that can be implicitly converted to a Dollars 
	// (especially a fundamental type like int). 
	// This would reduce the possibility of inadvertent errors.
	// like this:

	print(Dollars(5));

	return 0;
}