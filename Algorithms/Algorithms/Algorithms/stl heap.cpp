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

	//push the new number to the back of the container
	numbers.push_back(9.8);

	print_content();

	//create a heap out of the container
	create_new_heap();

	print_content();

	//again push the new number to the end of out container
	numbers.push_back(7.3);

	print_content();

	//create new heap with 7.3
	create_new_heap();

	print_content();

	//again, push back 5.5 to the end of our container
	numbers.push_back(5.5);

	print_content();

	//push the new number (5.5) and make heap out of our container
	std::push_heap(numbers.begin(), numbers.end());

	print_content();

	//remove the head of the heap but not from the numers container
	std::pop_heap(numbers.begin(), numbers.end());

	print_content();

	//i we will pop_head continuosly, we'll end up with the sorted collection

	//remove the number from the back, from our container
	numbers.pop_back();

	print_content();

	//sorted collection
	std::sort(numbers.begin(), numbers.end());

	print_content();



	return 0;
}