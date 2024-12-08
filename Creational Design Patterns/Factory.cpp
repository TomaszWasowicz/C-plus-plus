#include <iostream>
#include <memory>

class Product
{
public:
	virtual void operation() const = 0;
	virtual ~Product() = default;
};

class ConcreteProductA : public Product
{
public:
	void operation() const override
	{
		std::cout << "ConcreteProductA::operation()" << std::endl;
	}
};

class ConcreteProductB : public Product
{
public:
	void operation() const override
	{
		std::cout << "ConcreteProductB::operation()" << std::endl;
	}
};

class Creator
{
public:
	static std::unique_ptr<Product> createProduct(char type)
	{
		switch (type)
		{
		case 'A':
			return std::make_unique<ConcreteProductA>();
		case 'B':
			return std::make_unique<ConcreteProductB>();
		default:
			return nullptr;
		}
	}
};

int main()
{
	auto productA = Creator::createProduct('A');
	productA->operation();

	auto productB = Creator::createProduct('B');
	productB->operation();

	return 0;
}