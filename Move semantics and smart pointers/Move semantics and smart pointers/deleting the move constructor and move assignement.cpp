#include <iostream>
#include <string>
#include <string_view>

class Name
{
private:
	std::string m_name{};
public:
	Name(std::string_view name) : m_name{ name }
	{

	}

	Name(const Name& name) = delete;
	Name& operator = (const Name& name) = delete;
	Name(Name&& name) = delete;
	Name& operator = (Name&& name) = delete;

	const std::string& get() const { return m_name; }
};

int main()
{
	Name n1{ "Tomek" };
	//n1 = Name{ "Bartek" };    //b³¹d: move assignment deleted

	std::cout << n1.get() << '\n';

	return 0;
}