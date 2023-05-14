#include "Cents.h"
#include <iostream>

int main()
{
	Cents cents1{ 6 };
	Cents cents2{ 8 };
	Cents centsSum{ cents1 + cents2 };    //without the prototype in Cents.h, this won't compile
	std::cout << "I have " << centsSum.getCents() << " cents.\n";

	return 0;
}