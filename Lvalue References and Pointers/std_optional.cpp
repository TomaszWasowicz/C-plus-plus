#include <iostream>
#include <optional>		//std::optional C++17

std::optional<int> doIntDivsion(int x, int y)
{
	if (y == 0)
		return {};		//or return std::nullopt
	return x / y;
}

int main()
{
	std::optional<int> result1{ doIntDivsion(20,5) };

	if (result1)
		std::cout << "Result 1: " << *result1 << '\n';
	else
		std::cout << "Result 1: failed\n";

	std::optional<int> result2{ doIntDivsion(5,0) };

	if (result2)
		std::cout << "Result 2: " << *result2 << '\n';
	else
		std::cout << "Result 2: failed\n";

	return 0;
}