#include <iostream>

int value{ 5 };

void foo()
{
	std::cout << "global variable value: " << value << '\n';
}


int main()
{
	int value{ 7 };

	++value;

	std::cout << "local variable value: " << value << '\n';

	foo();

	return 0;
}