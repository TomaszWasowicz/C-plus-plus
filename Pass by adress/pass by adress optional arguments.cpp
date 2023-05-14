#include <iostream>
#include <string>

void greet(std::string* name = nullptr)
{
	std::cout << "Hello ";
	std::cout << (name ? *name : "guest") << '\n'; //tertiary operator

}

int main()
{
	greet();

	std::string joe{ "Joe" };
	greet(&joe);

	return 0;
}