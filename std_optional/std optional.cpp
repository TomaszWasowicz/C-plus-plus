#include <iostream>
#include <optional>

std::optional<int> doIntDivision(int x, int y)
{
	if (y == 0)
		return {};   //or return std::nullopt
	return x / y;
}	

int main()
{
	if (std::optional<int> result1{ doIntDivision(20,5) }; result1)
		std::cout << "Result 1: " << *result1 << '\n';
	else
		std::cout << "Result 1: failed\n ";


	if (std::optional<int> result2{ doIntDivision(5,0) }; result2)
		std::cout << "Result 2: " << *result2 << '\n';
	else
		std::cout << "Result 2: failed\n";

	return 0;
}