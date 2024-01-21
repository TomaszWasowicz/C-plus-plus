#include <iostream>
#include <string>
#include <utility>	// dla std::move

template<class T>
void myswapMove(T& a, T& b)
{
	T tmp{ std::move(a) };  //invokes move constructor
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	std::string x{ "abc" };
	std::string y{ "de" };

	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	myswapMove(x, y);

	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	return 0;
}