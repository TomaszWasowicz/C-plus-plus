#include <iostream>
#include <string_view>

class A
{
public:
	virtual std::string_view getName() const { return "A"; }
};

class B : public A
{
public:
	virtual std::string_view getName() const { return "B"; }
};

class C : public B
{
public: 
	virtual std::string_view getName() const { return "C"; }
};

class D : public C
{
public:
	virtual std::string_view getName() const { return "D"; }
};

int main()
{
	D d{};
	A const& rBase{ d };
	std::cout << "rBase is a " << rBase.getName() << '\n';

	return 0;
}