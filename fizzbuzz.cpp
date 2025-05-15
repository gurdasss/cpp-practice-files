#include <iostream>

void fizzBuzz(int n);

int main()
{
    fizzBuzz(150);
    return 0;
}

void fizzBuzz(int n)
{
    for (int i{1}; i <= n; i++)
    {
        bool flag{true};

        if (!(i % 3))
        {
            std::cout << "fizz";
            flag = false;
        }
        if (!(i % 5))
        {
            std::cout << "buzz";
            flag = false;
        }
        if (!(i % 7))
        {
            std::cout << "pop";
            flag = false;
        }

        if (flag)
            std::cout << i;

        std::cout << '\n';
    }
}