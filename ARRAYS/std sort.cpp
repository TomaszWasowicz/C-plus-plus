#include <iostream>
#include <algorithm>
#include <iterator>

int main()
{
	int array[]{ 30,50,20,10,40 };

	std::sort(std::begin(array), std::end(array));

	for (int i{ 0 }; i < static_cast<int>(std::size(array)); ++i)
		std::cout << array[i] << ' ';

	std::cout << '\n';

	return 0;
}
