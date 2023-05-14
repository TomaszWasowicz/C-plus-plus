#include <iostream>

class Something
{
private:
	static inline int s_idGenerator{ 1 };  // definition is not a subject to access control
	int m_id{};

public:
	Something()
		: m_id{ s_idGenerator++ }
	{

	}

	int getID() { return m_id; }
};

int main()
{
	Something first;
	Something second;
	Something third;

	std::cout << first.getID() << '\n';
	std::cout << second.getID() << '\n';
	std::cout << third.getID() << '\n';

	return 0;
}