#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

void printEmployee(const Employee& e)
{
    // Use member selection opeartor 
    //(.) to select member from reference to struct

    std::cout << "Id: " << e.id;
    std::cout << "  Age: " << e.age;
    std::cout << "  Wage: " << e.wage;
}

int main()
{
    Employee joe{ 1, 34, 65000.0 };

    ++joe.age;
    joe.wage = 68000.0;

    printEmployee(joe);

    return 0;
}