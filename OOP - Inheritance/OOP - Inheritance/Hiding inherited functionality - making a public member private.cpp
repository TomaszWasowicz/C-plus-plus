#include <iostream>
class Base
{
public:
	int m_value{};
};

class Derived : public Base
{
private:
	using Base::m_value;

public:
	Derived(int value) : Base{value}{}
};

int main()
{
	Derived derived{ 7 };

	//error: m_value is private in Derived
	std::cout << derived.m_value;

	Base& base{ static_cast<Base&>(derived) };
	
	//ok: m_value is public in Base
	std::cout << base.m_value;


	return 0;
}