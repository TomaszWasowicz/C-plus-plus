#include<iostream>
#include<algorithm>
#include<vector>

std::vector <float> numbers{};

void create_new_heap()
{
	std::make_heap(numbers.begin(), numbers.end());
}

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

	numbers.push_back(9.8);

	create_new_heap();

	print_content();

	numbers.push_back(7.3);

	print_content();

	create_new_heap();

	numbers.push_back(5.5);

	std::push_heap(numbers.begin(), numbers.end());

	print_content();

	return 0;
}