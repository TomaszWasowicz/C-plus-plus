#include <iostream>

int main()
{
	const int x{ 5 };
	const int& ref{ x };

	std::cout << ref << x << '\n';

	//ref = 6;  impossible referring to a const variable can't change the value

	int y{ 7 };
	const int& ref2{ y };

	std::cout << ref2 << y << '\n';
	
	y = 6; // zmiana wartosci jest dopuszczalna, wtedy zmienia sie rowniez wartosc referencji

	std::cout << ref2 << y << '\n';

	return 0;
} 