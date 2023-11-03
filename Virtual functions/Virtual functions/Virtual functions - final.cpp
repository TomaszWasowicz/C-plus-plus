#include <string_view>

class A
{
public:
	virtual std::string_view getName() { return "A"; }
};

class B final : public A							// FINAL dla calej klasy, uniemozliwia dziedziczenie
{
public:
	std::string_view getName() override final { return "B"; }    //FINAL dla override, uniemozliwa override
};

class C : public B // compile error: cannot inherit from final class
{
public:
	std::string_view getName() override { return "C"; }
};