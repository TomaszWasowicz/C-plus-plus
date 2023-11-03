#include <iostream>
#include <string>
#include <string_view>

class Person
{
public:
	std::string m_name{};
	int m_age{};

	Person(std::string_view name = "", int age = 0): m_name{name}, m_age{age}{}

	const std::string& getName() const {return m_name; }
	int getAge() const { return m_age; }

};

class Employee : public Person
{
public:
	double m_hourlySalary{};
	long m_employeeID{};

	Employee(double hourlySalary = 0.0, long employeeID = 0)
		: m_hourlySalary{hourlySalary},m_employeeID{employeeID}{}

	void printNameAndSalary() const
	{
		std::cout << m_name << ": " << m_hourlySalary << '\n';
	}
};

class Supervisor : public Employee
{
public:
	long m_overseesIDs[5]{};
};

int main()
{
	Employee Frank{ 20.25, 12345 };
	Frank.m_name = "Frank";   //m_name is public

	Frank.printNameAndSalary();

	return 0;
}