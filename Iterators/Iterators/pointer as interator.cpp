#include <array>
#include <iostream>

int main()
{
	std::array data{ 0,1,2,3,4,5,6 };

	auto begin{ &data[0] };

	auto end{ begin + std::size(data) };

	for (auto ptr{ begin }; ptr != end; ++ptr)
	{
		std::cout << *ptr << ' ';
	}
	std::cout << '\n';

	return 0;
}