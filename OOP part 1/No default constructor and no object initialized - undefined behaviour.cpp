#include <iostream>

class Fraction
{
private:
    // Removed initializers
    int m_numerator;
    int m_denominator;

public:
    // Removed default-constructor

    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

int main()
{
    Fraction frac;
    // frac is uninitialized, accessing its members causes undefined behavior
    std::cout << frac.getNumerator() << '/' << frac.getDenominator() << '\n';

    return 0;
}