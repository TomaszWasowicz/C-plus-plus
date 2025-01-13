#include <iostream>

class Fruit
{
public:
	// FruitType has been moved inside the class, under the public access specifier
		// It's renamed Type made an enum rather than an enum class
	enum Type
	{
		apple,
		banana,
		cherry
	};

private:
	Type m_type{};
	int m_percentageEaten{ 0 };

public:
	explicit Fruit(Type type) : m_type{ type }{}

	Type getType() const { return m_type; }
	int getPercentageEaten() const { return m_percentageEaten; }

	// Inside members of Fruit, it's not needed to have a prefix enumerators with FruitType::
	bool isCherry() const { return m_type == cherry; } 
};

int main()
{
	// Note: Outside the class, we have to access the enumerators via the Fruit:: prefix now

	if (Fruit apple{ Fruit::apple }; apple.getType() == Fruit::apple)
		std::cout << "I am an apple";
	else
		std::cout << "I am not an apple";

	return 0;
}