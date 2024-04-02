#include <algorithm>
#include <array>
#include < iostream>

int main()
{
	std::array arr{ 12,56,76,1,34 };

	std::cout << "Enter a value to search for and replace with: ";
	int search{};
	int replace{};
	std::cin >> search >> replace;

	//Input validation not checked here

	//std::find returns an iterator pointing to the found element or the end of the container

	auto found{ std::ranges::find(arr.begin(), arr.end(), search) };

	if (found == arr.end())
	{
		std::cout << "Could not find " << search << '\n';
	}
	else
	{
		*found = replace;
	}

	for (int i : arr)
	{
		std::cout << i << ' ';
	}

	std::cout << '\n';




	return 0;
}