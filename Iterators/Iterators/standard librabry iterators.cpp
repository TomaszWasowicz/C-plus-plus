#include <array>
#include <iostream>

int main()
{
	std::array array{ 1,2,3,4,5 };

	auto begin{ array.begin() };
	auto end{ array.end() };

	for (auto p{ begin }; p != end; ++p)
	{
		std::cout << *p << ' ';
	}

	std::cout << '\n';


	return 0;
}