#include<iostream>

struct Something
{
	int n;
	float f;
};


int main()
{
	int a{5};
	int b{6};

	Something structValue{};

	void* voidPtr{};  // void pointer can point to anything, but it doesn't
					//know what's it's pointing at
					//it cannot be dereferenced
					// first it has to be cast to another pointer

	voidPtr = &structValue;
	voidPtr = &a;
	voidPtr = &b;
	


	int* intPtr{ static_cast<int*>(voidPtr) }; //casting on to another pointer type

	std::cout << *intPtr << '\n'; // now it can be dereferenced








	return 0;
}