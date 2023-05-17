#include <iostream>

int& max(int& x, int& y)
{
	return (x > y) ? x : y;
}

int main()
{
	int x{ 5 };
	int y{ 6 };

	max(x, y) = 7;   // ustaw wiêksza ze zmiennych na 7

	std::cout << x << y;

	return 0;
}