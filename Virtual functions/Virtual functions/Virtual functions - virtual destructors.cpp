#include <iostream>
#include <memory>
#include <vector>

class Base
{
public:
	virtual ~Base()   //not virtual
	{
		std::cout << "Calling ~Base()\n";
	}
};

class Derived : public Base
{
private:
	std::unique_ptr<int[]> m_array;

public:
	explicit Derived(int length): m_array(std::make_unique<int[]>(length)){}

	virtual ~Derived() 
	{
		std::cout << "Calling ~Derived()\n";
	}
};

int main()
{
	std::unique_ptr<Derived> derived = std::make_unique<Derived>(5);
	std::unique_ptr<Base> base = std::move(derived);

	return 0;
}