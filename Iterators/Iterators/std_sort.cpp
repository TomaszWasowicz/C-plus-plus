#include <algorithm>
#include<array>
#include<iostream>

bool greater(int a, int b)
{
	//order a before b, if a is > b
	return(a > b);
}

int main()
{
	std::array arr{ 14,68,4,2,9 };

	//pass greater() to std::sort

	std::ranges::sort(arr, greater);

	for (int i : arr)
	{
		std::cout << i << ' ';
	}

	std::cout << '\n';

	return 0;
}