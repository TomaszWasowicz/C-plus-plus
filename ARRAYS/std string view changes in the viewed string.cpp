#include <iostream>
#include <string_view>

int main()
{
	char arr[]{ "Gold" };
	std::string_view str{ arr };

	std::cout << str << '\n'; // Gold

	// Change 'd' to 'f' in arr
	arr[3] = 'f';

	std::cout << str << '\n'; // Golf

	return 0;
}