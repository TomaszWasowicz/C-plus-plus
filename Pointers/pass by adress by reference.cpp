#include <iostream>

void nullify(int*& refptr)
{
	refptr = nullptr;
}

int main()
{
	int x{ 5 };
	int* ptr{ &x };

	std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

	nullify(ptr);

	std::cout << "ptr is: " << (ptr ? "non-null\n" : "null\n");

	return 0;
}