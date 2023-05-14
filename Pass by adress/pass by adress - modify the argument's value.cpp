#include <iostream>

void changeValue(int* ptr)
{
	*ptr = 6;
}

int main()
{
	int x{ 5 };
	std::cout << "x = " << x << '\n';	// value 5

	changeValue(&x);					// change the value to to 6

	std::cout << "x = " << x << '\n';

	return 0;
}