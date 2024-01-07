#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
	std::string m_name{};

public:
	Employee(std::string_view name)
		: m_name{ name }
	{
	}

	const std::string& getName() const { return m_name; }
};

void printEmployee(Employee e)      //has an Employee parameter
{
	std::cout << e.getName() << std::endl;
}

int main()
{
	//1st way 
	using namespace std::literals;
	printEmployee("Tomek"sv);      //supplying a sv string literal argument

	//2nd way
	printEmployee(Employee{ "Tomek" });   //explicitly construct an Employee, rather than implicitly create one

	return 0;
}