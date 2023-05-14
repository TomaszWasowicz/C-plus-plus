#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
	int m_id{};
	std::string m_name{};

public:
	Employee(int id=0, std::string_view name= ""):
		m_id{ id }, m_name{ name }
	{
		std::cout << "Employee" << m_name << " created.\n";
	}

	//Use a delegating constructor to minimize reduntant code
	Employee(std::string_view name) : Employee{ 0, name }
	{

	}

};

int main()
{
	Employee employee;

	

	return 0;
}