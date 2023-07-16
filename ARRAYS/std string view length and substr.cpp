#include <iostream>
#include<string_view>

int main()
{
	std::string_view text{"Trains are fast"};
	std::string_view str{text};

	std::cout << str.length() << '\n';
	std::cout << str.substr(0, str.find(' ')) << '\n';

	std::string_view more{str};

	std::cout << text << '\n' << str << '\n' << more;

	return 0;
}