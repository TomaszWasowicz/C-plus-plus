#include <iostream>

int main()
{
	bool b{};
	std::cout << "Wprowadz zmienna typu bool: ";		

	std::cin >> std::boolalpha;					// true albo false, wszystko inne to false

	std::cin >> b;
	std::cout << "Twoja zmienna typu bool to :" << b << '\n';


	return 0;
}