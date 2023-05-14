#include <functional>
#include <iostream>

int foo()
{
	return 5;
}

int goo()
{
	return 6;
}

int main()
{
	//declare a function pointer that returns an int and takes no parameters
	std::function<int()>fcnPtr{ &foo }; 


	//fcnPtr now points to function goo
	fcnPtr = &goo;

	//call the function just like normal
	std::cout << fcnPtr() << '\n';

	return 0;
}