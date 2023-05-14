#include <iostream>
#include <vector>

int main()
{
	std::vector<int>array(5);

	std::cout << "Arrays size: " << array.size() << '\n';

	for (int i : array)
		std::cout << i << ' ';

	std::cout << '\n';



	return 0;
}