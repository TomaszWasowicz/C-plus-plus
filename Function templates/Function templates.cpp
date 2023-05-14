#include<iostream>



template<typename T>		//deklaracja parametru T 
T max(T x, T y)
{
	return (x > y) ? x : y;
}

int main()
{

	std::cout << max<int>(1, 2) << '\n';

	return 0;



}