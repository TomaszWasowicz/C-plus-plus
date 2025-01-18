
#include <iostream>

class Accumulator
{
private:
    int m_value{ 0 };

public:
    void add(int value) { m_value += value; }

    // instead of:
    //friend void print(const Accumulator& accumulator);

    //use this:
    // reasonable access function
    int value() const { return m_value; }

};
//Instead of:
//void print(const Accumulator& accumulator)
//{
//    std::cout << accumulator.m_value; // and we need to modify this
//}

//use this:
// no longer a friend of Accumulator
void print(const Accumulator& accumulator)
{
    std::cout << accumulator.value(); // use access function instead of direct access
}

int main()
{
    Accumulator acc{};
    acc.add(5); //add 5 to the accumulator

    print(acc); //call the print() non-member function

    return 0;
}