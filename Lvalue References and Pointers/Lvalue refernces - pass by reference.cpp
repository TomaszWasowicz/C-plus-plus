#include <iostream>

void addONe(int y)
{
	++y;
}



int main()
{
	int x{ 5 };

	std::cout << "value = " << x << '\n';

	addONe(x);

	std::cout << "value = " << x << '\n';


	return 0;
}

