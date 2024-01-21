#include <iostream>
#include<string>
#include <string_view>

class Name
{
private:
	std::string m_name{};
public:
	Name(std::string_view name) : m_name{ name }
	{

	}

	Name(const Name& name) = default;
	Name& operator = (const Name& name) = default;

	// przy zmianie na default lub usunieciu move constructora bedzie dzialac
	// move constructor jest uprawniony do overload resolution i zwrocenie
	//przez wartosc 'joe' faworyzuje 'delete'owany move constructor
	//nad copy constructor'em

	Name(Name&& name) = delete;   
	Name& operator = (Name&& name) = delete;

	const std::string& get() const { return m_name; }
};

Name getJoe()
{
	Name joe{ "Joe" };
	return joe;         //b³¹d: move construtor jest w stanie 'delete'
}

int main()
{
	Name n { getJoe() };

	std::cout << n.get() << '\n';
	return 0;
}