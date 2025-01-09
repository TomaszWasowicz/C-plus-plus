#include <iostream>

template <typename T>
struct Pair
{
	T first{};
	T second;
};

//Alias template must be defined in a global scope

template <typename T>
using Coordinates = Pair<T>;    //Coordinates in as alies for Pair<T>

//also print function template needs to know that Coordinates template paramter T
// is a type template parameter

template<typename T>
void print(const Coordinates<T>& c)
{
	std::cout << c.first << ' ' << c.second << '\n';
}

int main()
{
	Coordinates<int> p1 {1, 2}; // before C++20: You have to explicitly specify
							//all the type template arguments

	Coordinates p2{ 3, 6 }; // in C++20, we can use alies template deduction
	                            // to deduce the template arguments in cases where CTAD works

	std::cout << p1.first << ' ' << p1.second << '\n';
	print(p1);
	std::cout << p2.first << ' ' << p2.second << '\n';

	return 0;
}