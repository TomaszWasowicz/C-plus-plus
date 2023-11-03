#include <iostream>

//Constructors: A -> B -> C
//Destructors: C -> B -> A

class A
{
public:
	A(int a)							// first A is constructed and prints A
	{
		std::cout << "A: " << a << '\n'; 
	}
};

class B : public A
{
public:
	B(int a, double b)					//second B is constructed and prints 4.3
		: A{ a }
	{
		std::cout << "B: " << b << '\n'; 
	}
};

class C : public B
{
public:
	C(int a, double b, char c)			//third C is constructed and prints R
		:B{ a,b }
	{
		std::cout << "C: " << c << '\n';
	}
};

int main()
{
	C c{ 5, 4.3, 'R' };

	return 0;
}