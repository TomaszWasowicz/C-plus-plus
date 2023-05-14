#include <iostream>

int add(int x, int y)
{
	return x + y;
}

int substract(int x, int y)
{
	return x - y;
}


int main()
{
	std::cout << "Enter first integer: " << '\n';
	int x{};
	std::cin >> x;

	std::cout << "Enter second integer: " << '\n';
	int y{};
	std::cin >> y;

	std::cout << "x + y = " << add(x,y) << '\n';
	std::cout << "x - y = " << substract(x, y) << '\n';


	return 0;
}