#include <iostream>
#include <typeinfo>

int main()
{
	int i{ 2 };
	double pola{ 3.5 };
	std::cout << typeid (i + pola).name() << ' ' << i + pola;



	return 0;
}