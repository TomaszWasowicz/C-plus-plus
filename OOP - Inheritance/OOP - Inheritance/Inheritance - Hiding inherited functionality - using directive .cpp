#include <iostream>

class Base
{
private:
	int m_value{};

public:
	Base(int value): m_value{value}{}

protected:
	void printValue() const { std::cout << m_value; }
};

class Derived : public Base
{
public:
	Derived(int value): Base{value}{}

	//Base::printValue was inherited as protected, so the public has no access
	//But we'are changing it to public via a using declaration

	using Base::printValue;
};

int main()
{
	Derived derived{ 7 };

	derived.printValue();

	return 0;
}