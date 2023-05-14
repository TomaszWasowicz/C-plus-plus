#include<iostream>

int main()
{
	constexpr int fibonacci[]{ 0,1,1,2,3,5,8,13,21,34,55,89 };

	//for (element_declaration: array)
	// statement

	for (int number : fibonacci) //iterare over array fibonacci
	{
		std::cout << number << ' '; //access the array element
								//for this iteration
								//through variable "number"
	}

	std::cout << '\n';




	return 0;
}