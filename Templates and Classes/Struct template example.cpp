#include <iostream>

template<typename T,typename U>
struct Pair
{
	T first{};
	U second{};
};

template <typename T, typename U>
void print(Pair <T, U > p)
{
	std::cout << '[' << p.first << ", " << p.second << ']';
}


int main()
{
	Pair<int,int> p1{ 5,6 };   //instantiates Pair<int> and creates object p1
	std::cout << p1.first << ' ' << p1.second << '\n';
	print(p1); //for example, calls print() with object p1

	Pair<double, int> p2{ 1.2, 3 };   //instatiates Pair<double> and creates object p2
	std::cout << p2.first << ' ' << p2.second << '\n';
	print(p2);

	Pair<double, double> p3{ 7.8, 9.0 }; //instantiates Pair<double> and creates object p3
	std::cout << p3.first << ' ' << p3.second << '\n';
	print(p3);
	


	return 0;
}