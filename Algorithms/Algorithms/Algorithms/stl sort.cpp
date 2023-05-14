#include<iostream>
#include<algorithm>
#include<vector>

std::vector <float> numbers{};


void print_content()
{
	for (float i : numbers)
		std::cout << i << ' ';
	std::cout << '\n';
}


int main()
{
	numbers = { 10,9,8,7,6,5,4,3,2,1 };

	print_content();

	//push the new number to the back of the container
	numbers.push_back(9.8);

	print_content();

	//sorted collection
	std::sort(numbers.begin(), numbers.end());

	print_content();

	//partial sort

	std::partial_sort(numbers.begin(), numbers.end() +3);



	return 0;
}