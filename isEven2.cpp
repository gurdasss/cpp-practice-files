#include <iostream>

bool isEven(int n);

int main()
{
    std::cout << "Enter an integer: ";
    int n;
    std::cin >> n;

    if (isEven(n))
        std::cout << n << " is even\n";
    else
        std::cout << n << " is odd\n";

    return 0;
}

bool isEven(int n)
{
    return !(n % 2);
}