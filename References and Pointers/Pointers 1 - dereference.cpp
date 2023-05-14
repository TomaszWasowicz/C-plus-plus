#include <iostream>

int main()
{
	int x{ 5 };
	std::cout << x << '\n';			// x
	std::cout << &x << '\n';		//adres x

	std::cout << *(&x) << '\n';  // dereferencja - wartosc pod adresem



	return 0;
}