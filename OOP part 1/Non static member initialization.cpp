#include <iostream>

class Rectangle
{
private:
    double m_length{ 1.0 };
    double m_width{ 1.0 };

public:


    // note: No default constructor provided in this example
    Rectangle(double length, double width): m_length{ length }, m_width{ width }
    {
        // m_length and m_width are initialized by the constructor (the default values aren't used)
    }

    Rectangle(double length): m_length{length}{}

    void print() const
    {
        std::cout << "length: " << m_length << ", width: " << m_width << '\n';
    }


    //Rectangle() = default;
};

int main()
{
    //Rectangle x1{};
    // will not compile, no default constructor exists, even though members have default initialization values

    Rectangle x{2.0, 3.0};
    x.print();

    Rectangle x2{ 2.0 };
    x2.print();

    return 0;
}