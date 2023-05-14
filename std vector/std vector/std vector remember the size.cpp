#include <iostream>
#include <vector>

void printLength(const std::vector<int>& array)
{
	std::cout << "The length is: " << array.size() << '\n';
}

int main()
{
	std::vector array{ 9,7,5,3,1 };
	printLength(array);

	std::vector<int> empty{};
	printLength(empty);


	return 0;
}