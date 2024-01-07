#include <iostream>

int main()
{
	

	{
		int x{ 5 };
		std::cout << x << '\n';
		int& ref{ x };
		std::cout << ref << '\n';
	}
	
	std::cout << ref << '\n';
	


	return 0;
}