#include <iostream>
#include <cstdint> // for std::int64_t
#include <cassert> // for assert

//exp musi byc nie-negatywne

std::int64_t powint(int base, int exp)
{
	assert(exp > 0 && "powint: exp parameter has negative value");

	std::int64_t result{ 1 };
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}

	return result;
}

int main()
{
	std::cout << powint(7, 12);    //7 do 12 potêgi

	return 0;
}