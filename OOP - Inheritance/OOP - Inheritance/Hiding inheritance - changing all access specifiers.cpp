#include <iostream>

class Base
{
public:
	int m_value{};

	int getValue() { return m_value; }
	int getValue(int) { return m_value; }
};

class Derived : public Base
{
private:
	using Base::getValue;     //make ALL getValue functions private

public:
	Derived(int value) : Base{ value }
	{
	}
};

int main()
{
	Derived derived{ 7 };
	std::cout << derived.m_value; 

	Base& base{ static_cast<Base&>(derived) };
	std::cout << base.m_value; 

	std::cout << derived.getValue();		//error: getValue() is private in Derived
	std::cout << derived.getValue(5);		//error: getValue(int) is private in Derived

	return 0;
}