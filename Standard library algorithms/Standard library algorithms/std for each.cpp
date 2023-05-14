#include<iostream>
#include<algorithm>
#include<array>

void doubleNumber(int& i)
{
	i *= 2;
}

void tripleNumber(int& k)
{
	k *= 3;
}

int main()
{
	std::array arr{ 1,2,3,4 };

	std::for_each(arr.begin(), arr.end(), doubleNumber);

	for (int i : arr)
	{
		std::cout << i << ' ';
	}

	std::cout << '\n';




	std::array arr2{ 2,4,5,6 };

	std::ranges::for_each(arr2, tripleNumber); 
	// Since C++20, we don't have to use begin() and end().
	// 
	// std::for_each(arr.begin(), arr.end(), doubleNumber); // Before C++20

	for (auto& k : arr2)
	{
		tripleNumber(k);
	}

	std::cout << '\n';


	return 0;
}