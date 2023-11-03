#include <string_view>
#include <iostream>

class Base
{
public:
	virtual ~Base() = default;
	virtual std::string_view getName() const { return "Base"; }
};

class Derived : public Base
{
public:
	virtual std::string_view getName() const { return "Derived"; }
};

int main()
{
	Derived derived{};
	const Base& base{ derived };

	//Calls Base::getName() instead of the virtualized Derived::getName() - prints Base
	std::cout << base.Base::getName() << '\n';

	//calls Dervied.getName() - prints Dervied
	std::cout << base.getName() << '\n';

	return 0;
}

