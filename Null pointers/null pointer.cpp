#include <iostream>

int main()
{
	int* ptr{}; // a null pointer


	int x{ 5 };

	int& ref{ x };

	ptr = &x;    // ptr pointing at object x ( not longer a null pointer )

	std::cout << ref << '\n';        //  5

	std::cout << &x << '\n';		//  adres 5

	std::cout << *ptr << '\n'; //dereference  // 5

	std::cout << '\n';
	
	int value{ 6 };

	int& ref2{ value };

	std::cout << ref2 << '\n';   //6

	int* ptr2{ &value };		

	std::cout << ptr2 << '\n';	//adress pointera
	std::cout << *ptr2 << '\n'; // dereferancja referencji 6

	ptr2 = nullptr;				

	std::cout << ptr2 << '\n';	// adres null


	float* ptr{ 0 };

	float* ptr3;

	ptr3 = 0;
	ptr3 = NULL;

	std::cout << ptr3 << '\n';

	return 0;

}