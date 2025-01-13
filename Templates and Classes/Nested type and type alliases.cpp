#include <iostream>
#include <string>
#include <string_view>

class Employee
{
public:
	using IDType = int;

private:
	std::string m_name{};
	IDType m_id{};
	double m_wage{};

public:
	Employee(std::string_view name, IDType id, double wage) 
		: m_name{ name }, 
		m_id{ id }, 
		m_wage{ wage } 
	{}

	const std::string& getName() const { return m_name; }
	IDType getID() const {return m_id; }
};

int main()
{
	Employee john{ "John", 1, 45000.0 };
	Employee::IDType id{john.getID()};   //must use fully qualified name outside the class

	std::cout << john.getName() << " has id: " << id << '\n';

	return 0;
}