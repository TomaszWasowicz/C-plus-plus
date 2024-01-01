#include <iostream>

void PrintName(const std::string& name)		//lvalue reference <- can take only lvalue, unless it is const
{
	std::cout << "[lvalue]" << name << std::endl;   // lvalue has some kind of storage in it
}

void PrintName(std::string&& name) //rvalue reference
{
	std::cout << "[rvalue]" << name << std::endl;   //rvalue is a temporary value
}

int main()
{


	std::string firstName = "Tomek";
	std::string lastName = "Wasowicz";

	std::string fullName = firstName + ' ' + lastName;

	PrintName(fullName);
	PrintName(firstName + ' ' + lastName);

	std::cin.get();
}
	