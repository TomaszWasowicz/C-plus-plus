#include <iostream>

void print(char c, int x) 
// second argument matches char -> int via promotion
{
	std::cout << 'a';
}

void print(char c, double x)
{
	std::cout << 'b';
}

void print(char c, float x)
{
	std::cout << 'c';
}

int main()
{
	print('x', 'a');
}