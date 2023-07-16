#include <iostream>
#include <array>

int main()
{
	constexpr std::array <int, 12> fibonacci{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

	for (int number : fibonacci)
	{
		std::cout << number << ' ';
	}

	std::cout << '\n';

	return 0;
}