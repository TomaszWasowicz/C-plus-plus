#include <iostream>

int main()
{
	std::cout << std::boolalpha;		// std::boolalpha  - zamienia 1 i 0 na true i false

	std::cout << true << '\n';
	std::cout << false << '\n';


	bool b1{ true };
	bool b2{ false };
	b1 = false;

	bool b3{};    //inicjalizacja defaultowa
	bool b4{ !true };
	bool b5{ !false };

	std::cout << b1 << b2 << b3 << b4 << b5 << '\n';

	return 0;
}