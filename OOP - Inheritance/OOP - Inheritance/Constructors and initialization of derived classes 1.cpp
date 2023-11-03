#include <iostream>

class Base
{
private:   //can be public here too
    int m_id{};

public:             //there doesn't need to be anything specified, when above all is public
    Base(int id = 0)
        : m_id{ id }
    {
    }

    int getId() const { return m_id; }
};

class Derived : public Base
{
private:
    double m_cost{};

public:
    Derived(double cost = 0.0, int id=0)
        :Base{id}           //call Base(int) constructor with value id
        , m_cost{ cost }
    {
    }

    double getCost() const { return m_cost; }
};


int main()
{
    Derived derived{ 1.3, 5 }; // use Derived(double, int) constructor
    std::cout << "Id: " << derived.getId() << '\n';
    std::cout << "Cost: " << derived.getCost() << '\n';

    return 0;
}