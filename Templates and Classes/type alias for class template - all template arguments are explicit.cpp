#include <iostream>

template <typename T>
struct Pair
{
	T first{};
	T second;
};

template <typename T>
void print(const Pair<T>& p)
{
	std::cout << p.first << ' ' << p.second << '\n';
}

int main()
{
	using Point = Pair<int>;    //normal type alias
	Point p{ 1,2 };

	print (p);

	return 0;
}