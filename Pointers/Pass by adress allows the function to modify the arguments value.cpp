#include <iostream>

void changeValue(int* ptr)
{
	*ptr = 6;
}

int main()
{
	int x{ 5 };

	std::cout << "x = " << x << '\n';

	changeValue(&x);

	std::cout << "x = " << x << '\n';


	return 0;
}