#include <vector>
#include <iostream>

int main()
{
	std::vector array{ 2,3,4,5,7 };
	std::cout << "The array size is: " << array.size() << '\n';

	array.resize(5);
	std::cout << "The array size is: " << array.size() << '\n';


	array.resize(3);	
	std::cout << "The array size is: " << array.size() << '\n';

	for (int i : array)
		std::cout << i << ' ';

	std::cout << '\n';




	return 0;
}