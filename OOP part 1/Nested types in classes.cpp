#include <iostream>

class Fruit
{
public:
	// Note: we've moved FruitType inside the class, under the public access specifier
	// We've also changed it from an enum class to an enum
	enum class FruitType
	{
		apple,
		banana,
		cherry
	};

private:
	FruitType m_type{};
	int m_percentageEaten{ 0 };

public:
	explicit Fruit(FruitType type) :
		m_type{ type }
	{
	}

	FruitType getType() const { return m_type; }
	int getPercentageEaten() const { return m_percentageEaten; }
};

int main()
{
	// Note: we access the FruitType via Fruit now

	if (Fruit apple{ Fruit::FruitType::apple}; apple.getType() == Fruit::FruitType::apple)
		std::cout << "I am an apple";
	else
		std::cout << "I am not an apple";

	return 0;
}