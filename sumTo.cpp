#include <iostream>

int sumTo(int n);

int main()
{
    std::cout << sumTo(5) << '\n';
    return 0;
}

int sumTo(int n)
{
    int result{};
    for (int i{1}; i <= n; i++)
    {
        result += i;
    }

    return result;
}