#include <iostream>

void addOne(int& y)
{
	++y;
}


int main()
{
	int x{ 5 };

	std::cout << "value = " << x << '\n';

	addOne(x);

	std::cout << "value = " << x << '\n';

	return 0;
}