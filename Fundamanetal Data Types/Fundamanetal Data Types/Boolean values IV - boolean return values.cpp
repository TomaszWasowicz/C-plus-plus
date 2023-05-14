#include <iostream>

bool isEqual(int x, int y)
{
	return (x == y);			//operator == zwróci true albo false
}



int main()
{
	std::cout << "Enter an integer x: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter an integer y: ";
	int y{};
	std::cin >> y;

	std::cout << std::boolalpha;

	std::cout << "Are " << x << " and " << y << " equal? " << '\n';
	std::cout << isEqual(x, y);							


	return 0;
}