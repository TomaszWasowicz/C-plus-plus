#include <iostream>

int main()
{
	short s = 3; // convert int to short
	long l = 3; // convert int to long
	char ch = s; // convert short to char

	float f = 3.0; // convert double to float
	long double ld = 3.0; // convert double to long double

	int i = 3.5; // convert double to int

	double d = 3; // convert int to double

	bool b1 = 3; // convert int to bool
	bool b2 = 3.0; // convert double to bool

	int i2{ 2 };
	short s2 = i2; // convert from int to short
	std::cout << s << '\n';

	double d2{ 0.1234 };
	float f2 = d2;
	std::cout << f2 << '\n';


	return 0;
}