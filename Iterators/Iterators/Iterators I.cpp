#include <iostream>
#include <cstddef>
#include <array>

int main()
{
	//std::array
	std::array<int, 7> data{ 0,1,2,3,4,5,6 };
	std::size_t length{ std::size(data) };

	//while loop
	std::size_t index{ 0 };
	while (index != length)
	{
		std::cout << data[index] << ' ';
		++index;
	}

	std::cout << '\n';

	//for loop with explicit index
	for (index = 0; index < length; ++index)
	{
		std::cout << data[index] << ' ';
	}

	std::cout << '\n';

	//for loop with pointer
	for (auto ptr{ &data[0] }; ptr != (&data[0] + length); ++ptr)
	{
		std::cout << *ptr << ' ';
	}

	std::cout << '\n';

	//for each loop

	for (int i : data)
	{
		std::cout << i << ' ';
	}
	
	std::cout << '\n';

	return 0;

}