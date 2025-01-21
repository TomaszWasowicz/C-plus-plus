#include <iostream>

template<typename T>
class Storage
{
private:
	T m_value{};
public:
	explicit Storage(T value) : m_value{value}{}

	void print()
	{
		std::cout << m_value << '\n';
	}
};
int main()
{
	Storage i{ 5 };
	Storage d{ 6.7 };

	i.print();
	d.print();

	return 0;
}