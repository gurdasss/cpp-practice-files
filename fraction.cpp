#include <iostream>

struct Fraction
{
    int numerator{};
    int denominator{1};
};

std::istream &operator>>(std::istream &in, Fraction &fraction)
{
    std::cout << "Enter a value for the numerator: ";
    in >> fraction.numerator;

    std::cout << "Enter a value for the denominator: ";
    in >> fraction.denominator;

    return in;
}

Fraction multiplyTwoFraction(const Fraction &a, const Fraction &b)
{
    return Fraction{
        (a.numerator * b.numerator),
        (a.denominator * b.denominator),
    };
}

std::ostream &operator<<(std::ostream &out, const Fraction &fraction)
{
    out << fraction.numerator
        << '/'
        << fraction.denominator;

    return out;
}

int main()
{
    Fraction exp1{};
    std::cin >> exp1;

    std::cout << '\n';

    Fraction exp2{};
    std::cin >> exp2;

    std::cout << "Your fractions multiplied together: "
              << multiplyTwoFraction(exp1, exp2)
              << '\n';

    return 0;
}