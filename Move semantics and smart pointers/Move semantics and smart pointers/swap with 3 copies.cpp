#include <iostream>
#include <string>

template<class T>
void myswapCopy(T& a, T& b)
{
	T tmp{ a };
	a = b;
	b = tmp;
}

int main()
{
	std::string x{ "abc" };
	std::string y{ "de" };

	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	myswapCopy(x, y);

	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';


	return 0;
}