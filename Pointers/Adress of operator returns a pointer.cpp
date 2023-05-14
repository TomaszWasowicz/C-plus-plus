#include <iostream>
#include <typeinfo>

int main()
{
	int x{ 4 };
	std::cout << typeid(&x).name() << '\n';  //adress of operator returns a pointer containing the adress of the operand
											//whose type is dervied from the argument
											//taking adress of an int willl retunr the adress in an int pointer

	int* ptr(&x);
	std::cout << *ptr << '\n';		//adress
	std::cout << *ptr << '\n';		// pointer to a value

	return 0;
}