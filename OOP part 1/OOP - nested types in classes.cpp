#include <iostream>

class Fruit
{
public:

	enum FruitType
	{
		apple,
		banana,
		cherry
	};

private:
	FruitType m_type{};
	int m_percentageEasten{ 0 };

public:
	Fruit(FruitType type) :
		m_type{ type }
	{

	}

	FruitType getType() const { return m_type; }
	int getPercentageEaten() const { return m_percentageEasten; }
};

int main()
{
	Fruit apple{ Fruit::apple };

	if (apple.getType() == Fruit::apple)
		std::cout << "I'm an apple";
	else
		std::cout << "I'm not an apple";

	return 0;
}