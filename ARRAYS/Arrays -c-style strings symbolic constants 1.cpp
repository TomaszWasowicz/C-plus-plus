#include <iostream>

int main()
{
	const char* array{ "Tomek" }; //string literals have static duration
	
	// and they die at the end of the program
									
	std::cout << array << '\n';


	return 0;
}