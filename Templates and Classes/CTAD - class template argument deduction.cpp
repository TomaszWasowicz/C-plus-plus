#include <iostream>
#include <utility>

template <typename T=int, typename U=int> // T and U deafulted to int
struct Pair
{
	T first{};
	U second{};
};

struct Foo
{
	std::pair<int, int> f1{ 1,2 }; // ok, template arguments are explicitly specified
	// std::pair f2{ 1,2 };		CTAD wil not work with initializing a non-static member
};

template<typename T, typename U>
Pair(T, U) -> Pair<T , U >;


void print(std::pair p) //complie error, CTAD can't be used here
{
	std::cout << p.first << ' ' << p.second << '\n'
}

template <typename T, typename U>  // this will compile
void print_me(std::pair <T, U> p)
{
	std::cout << p.first << ' ' << p.second << '\n';
}


int main()
{
	Pair<int, int> p1{ 1,2 };
	Pair p2{ 1,2 };

	Pair p3;   // works when template parameters T and U are defaulted to int

	std::pair p{ 1,2 };  // p deduced to std::apir<int,int>

	print_me(p);
	

	return 0;
}