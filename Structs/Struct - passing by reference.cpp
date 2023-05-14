#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

void printEmployee(const Employee& employee) //pass by reference
{
    std::cout << "ID:   " << employee.id << '\n';
    std::cout << "Age:  " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

int main()
{
    Employee joe{ 14, 32, 24.15 };
    Employee frank{ 15, 28, 18.27 };

    printEmployee(joe);

    std::cout << '\n';

    printEmployee(frank);

    return 0;
}