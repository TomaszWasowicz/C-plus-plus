/*
A nested class does not have access to the this pointer of the outer (containing) class, 
so nested classes can not directly access the members of the outer class. 
This is because a nested class can be instantiated independently of the outer class 
(and in such a case, there would be no outer class members to access!)

However, because nested classes are members of the outer class, 
they can access any private members of the outer class that are in scope.

*/

#include <iostream>
#include <string>
#include <string_view>

class Employee
{
public:
	using IDType = int;

	class Printer
	{
	public:
		void print(const Employee& e) const
		{
			// Printer can't access Employee's 'this" pointer
			// so you can't print m_name and m_id directly
			// Instead, we have to pass in an Employee object to use
			// because Printer is a member of Employee,
			// we can access private members e.m_name and e.m_id directly
			
			std::cout << e.m_name << " has id: " << e.m_id << '\n';
		}
	};

private:
	std::string m_name{};
	IDType m_id{};
	double m_wage{};

public:
	Employee(std::string_view name, IDType id, double wage)
		:m_name{name}
		, m_id{id}
		,m_wage{wage}
	{}
};

int main()
{
	const Employee john{"John", 1, 45000.0};
	Employee::Printer printer{};   //instantiate an object of the inner class 'Printer'
	printer.print(john);

	return 0;
}