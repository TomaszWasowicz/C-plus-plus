#include <cassert>

class Fraction
{
private:
    int m_numerator {};
    int m_denominator {};

public:
    Fraction() // default constructor
    {
         m_numerator = 0;
         m_denominator = 1;
    }

    // Constructor with two parameters, one parameter having a default value
    Fraction(int numerator, int denominator=1)
    {
        assert(denominator != 0);
        m_numerator = numerator;
        m_denominator = denominator;
    }

    int getNumerator() const { return m_numerator; }
    int getDenominator() const { return m_denominator; }
    double getValue() const { return static_cast<double>(m_numerator) / m_denominator; }
};

int main()
{
    Fraction trzynacztery { 5,3 };
    Fraction piecnatrzy(5, 7);
    Fraction osiem(8);   // drugim parametrem bedzie 1

    return 0;
}