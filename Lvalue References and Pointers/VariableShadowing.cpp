#include <iostream>

int main()
{
	int apples{ 5 };

	{
		std::cout << apples << '\n';

		int apples{ 0 };

		apples = 10;

		std::cout << apples << '\n';
	}

	std::cout << apples << '\n';

	return 0;
