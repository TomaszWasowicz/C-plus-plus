#include <functional>  //for std::reference_wrapper
#include <iostream>
#include <optional> // for std::optional, since C++ 17
#include <string>

void greet(std::optional<std::reference_wrapper<const std::string>> name = std::nullopt)
{
	std::cout << "Hello ";
	std::cout << (name ? name->get() : "guest") << '\n';   //must use name->() here instead of *name
}

int main()
{
	greet();

	std::string joe{ "Joe" };
	greet(joe);  //no need to take address here

	return 0;
}