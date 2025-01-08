#include <iostream>
#include <utility>

template <typename T, typename U>
void print(std::pair<T, U> p)
{
	std::cout << '[' << p.first << ", " << p.second << ']';
}

int main()
{
	std::pair<int, double> p1{ 1, 2.3 };
	std::pair<double, int> p2{ 4.5, 6 };
	std::pair<int, int> p3{ 7,8 };

	print(p1);
	print(p2);
	print(p3);

	return 0;
}