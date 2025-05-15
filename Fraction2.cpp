#include <iostream>
#include <cassert> // for assert()

class Fraction
{
public:
    explicit Fraction(int numerator, int denominator)
        : m_numerator{numerator},
          m_denominator{denominator}
    {
        assert(denominator && "Denominator must be > 0");
    }

    void print() const
    {
        std::cout << m_numerator << "/" << m_denominator << '\n';
    }

    Fraction multiply(const Fraction &fraction2) const
    {
        return Fraction{
            m_numerator * fraction2.m_numerator,
            m_denominator * fraction2.m_denominator,
        };
    }

private:
    int m_numerator{0};
    int m_denominator{1};
};

int main()
{
    Fraction f1{2, 5};
    Fraction f2{5, 2};

    std::cout << "Your fractions multiplied together: ";

    f1.multiply(f2).print();

    return 0;
}