#include <iostream>

class Base
{
protected:
	int m_value{};

public:
	Base(int value): m_value{value}{}

	void identify() const { std::cout << "I am a Base\n"; }
};
class Derived : public Base
{
public:
	Derived(int value) : Base{value} {}

	int getValue() const { return m_value; }
};

int main()
{
	Derived derived{ 5 };
	std::cout << "derived has value " << derived.getValue() << '\n';

	Base base{ 5 };

	//objects of type Base have no access to the getValue() function in Derived

	std::cout << "base has value " << base.getValue() << '\n';

	return 0;
}