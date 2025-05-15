#include <iostream>

int getInteger();
constexpr bool isEven(const int n);

int main()
{
    const int num{getInteger()};

    std::cout << num;
    if (isEven(num))
        std::cout << " is Even.\n";
    else
        std::cout << " is Odd.\n";

    return 0;
}

int getInteger()
{
    std::cout << "Enter an integer: ";
    int num{};
    std::cin >> num;

    return num;
}

constexpr bool isEven(const int n)
{
    return (n % 2) == 0;
}