#include <string>
#include <iostream>

class Person
{
public:
	std::string m_name{};
	int m_age{};

	Person(const std::string& name = "", int age = 0)
		: m_name{ name }, m_age{ age }
	{
	}

	const std::string& getName() const { return m_name; }
	int getAge() const { return m_age; }
};

class BaseballPlayer: public Person   // dodajê :public Person i klasa staje siê 'derived' - pochodn¹
{
public:
	double m_battingAverage{};
	int m_homeRuns{};

	BaseballPlayer (double battingAverage = 0.0, int homeRuns = 0)
		: m_battingAverage{ battingAverage }, m_homeRuns{ homeRuns }
	{
	}
};

class Employee : public Person
{
public:
	double m_hourlySalary{};
	long m_employeeID{};

	Employee(double hourlySalary = 0.0, long employeeID = 0)
		: m_hourlySalary{ hourlySalary }, m_employeeID{ employeeID }
	{
	}

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
	BaseballPlayer joe{};

	joe.m_name = "Joe";

	std::cout << joe.getName() << '\n';


	Employee frank{ 20.25, 12345 };

	frank.m_name = "Frank";

	frank.printNameAndSalary();



	Supervisor james{};

	james.m_name = "James";

	james.m_overseesIDs[4];

	std::cout << james.getName() << '\n';

	return 0;
}

