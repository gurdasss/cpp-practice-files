#include <iostream>

bool isPrime(int n);

int main()
{
    int num{};
    std::cout << "Enter an integer between 0 to 9: ";
    std::cin >> num;

    if (isPrime(num))
    {
        std::cout << num << " is a prime number.\n";
    }
    else
    {
        std::cout << num << " is not a prime number.\n";
    }

    return 0;
}

bool isPrime(int n)
{

    if (n == 2)
        return true;
    else if (n == 3)
        return true;
    else if (n == 5)
        return true;
    else if (n == 7)
        return 7;

    return false;
}