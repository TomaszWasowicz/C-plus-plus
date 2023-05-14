#include <iostream>

class Something
{
private:
    int m_value1{};
    double m_value2{};
    char m_value3{};
public:
    Something()
    {
        m_value1 = 1;                //assignments
        m_value2 = 2.2;
        m_value3 = 'c';
    }

    void print()
    {
        std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
    }
};

class Nothing
{
private:
    int n_value1{};
    double n_value2{};
    char n_value3{};
public:
    Nothing() : n_value1{ 2 }, n_value2{ 3.2 }, n_value3{ 'd' }     // Initialize our member variables
    {
        // No need for assignment here
    }

    void printNothing()
    {
        std::cout << "Nothing(" << n_value1 << ", " << n_value2 << ", " << n_value3 << ")\n";
    }
};

int main()
{
    Nothing nothing{};        // value1 = 1, value2=2.2, value3 gets default value 'c'
    nothing.printNothing();

    Something something{};
    something.print();

    return 0;
}