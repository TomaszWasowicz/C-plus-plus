#include <iostream>
#include <vector>

int main()
{
	std::vector<bool>array{ true, false, true, false, true };
	std::cout << "the array's length is: " << array.size() << '\n';

	for (int i : array)
		std::cout << i << '\n';

	std::cout << '\n';





	return 0;
}