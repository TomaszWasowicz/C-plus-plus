#include <iostream>

class Something
{
private:
    int m_value1{};
    double m_value2{};
    char m_value3{};
    const int m_value;

public:  // INICJALIZACJA WG LISTY W KLASIE
    Something(int value1, double value2, char value3 = 'c') 
        : m_value1{1}, m_value2{2.2}, m_value3{'c'}, m_value{5} // Initialize our member variables
    {
        // No need for assignment here
    }

    void print()
    {
        std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " 
            << m_value3 << ',' << m_value << ")\n";
    }
};

int main()
{
    Something something{1,2.2};  // value1 = 1, value2=2.2, value3 gets default value 'c'
    something.print();
    return 0;
}