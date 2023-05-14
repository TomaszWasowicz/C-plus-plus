#include <iostream>
#include <string>

int main()
{
	std::cout << "Enter your name: ";
	std::string name{};
	std::cin >> name;  // cin przyjmuje tylko ciag znakow do spacji

	std::cout << "Enter your age: ";
	std::string age{};
	std::cin >> age;

	std::cout << "Your name is " << name << " and your age is " << age << '\n';





	return 0;


}