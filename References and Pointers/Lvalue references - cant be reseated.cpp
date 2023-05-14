#include <iostream>

int main()
{
	int x{ 5 };

	int y{ 6 };

	int ref{ x };

	std::cout << ref;

	ref = y;

	std::cout << x << ref << y;



	return 0;
}