#include <iostream>

int main()
{
    constexpr short start{};
    constexpr short end{20};

    for (short i = start; i <= end; i++)
    {
        if (!(i % 2))
            std::cout << i << '\n';
    }
    return 0;
}