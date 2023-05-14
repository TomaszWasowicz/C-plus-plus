#include <cassert>

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    // Default constructor
    Fraction(int numerator = 0, int denominator = 1)
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
    Fraction zero;
    Fraction zero{};
    Fraction six{ 6 };
    Fraction fiveThirds{ 5,3 };

    return 0;
}