#include <iostream>

class Something
{
private:
	static inline int s_idGenerator{ 1 };
	int m_id{};

public:
	//grab the next value from the id generator
	Something() : m_id{ s_idGenerator++ } {}

	int getID() const { return m_id; }
};

int main()
{
	Something first{};
	Something second{};
	Something third{};

	std::cout << "First: " << first.getID() << '\n';
	std::cout << "Second: " << second.getID() << '\n';
	std::cout << "Third: " << third.getID() << '\n';

	return 0;
}