#include <iostream>

int main()
{

	int x{ 10 };
	int y{ 4 };
	int i{ 100 };

	char ch{ static_cast<char>(i) }; // static_cast z int na char
	
	double d{ static_cast<double>(x) / y }; //static_cast z int na double

	

	std::cout << d << ch;

	return 0;

}