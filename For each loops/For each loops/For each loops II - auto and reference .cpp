#include <iostream>

int main()
{
	constexpr int fibonacci[]{ 0,1,1,2,3,5,6,13,21,34,55,89 };
	for (auto number : fibonacci)
	{
		std::cout << number << ' ';
	}

	std::cout << '\n';


	std::string array[]{ "peter","likes","frozen","yogurt" };
	for (const auto& element : array)
	{
		std::cout << element << ' ';
	}



	return 0;
}