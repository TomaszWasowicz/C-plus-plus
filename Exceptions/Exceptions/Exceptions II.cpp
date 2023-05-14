#include <iostream>

int main()
{
	try
	{
		throw 4.5;
		std::cout << "this never prints\n";
	}
	catch (double x)   //handle expection of a double type
	{
		std::cerr << "We caught a double of a value: " << x << '\n';
	}


	return 0;
}