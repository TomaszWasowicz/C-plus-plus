#include <iostream>
#include<cassert>

void print(const int* ptr)
{
	assert(ptr);
	if (!ptr)
		return;

	std::cout << *ptr;
}

int main()
{
	int x{ 5 };

	print(&x);
	print(nullptr);

	return 0;
}