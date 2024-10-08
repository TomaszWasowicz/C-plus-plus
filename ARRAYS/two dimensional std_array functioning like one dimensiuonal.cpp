#include <iostream>
#include <array>

template<typename T, std::size_t Row, std::size_t Col>
void printArray(std::array<std::array<T, Col>, Row>& arr)
{
	for (const auto& arow : arr)
	{
		for (const auto& e : arow)
			std::cout << e << ' ';

		std::cout << '\n';
	}
}

int main()
{
	std::array<std::array<int, 4>, 3> arr
	{
		{
			{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
}
	};

	printArray(arr);

	return 0;
}