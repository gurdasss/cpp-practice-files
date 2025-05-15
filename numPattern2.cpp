#include <iostream>

int main()
{
    constexpr char filler{' '};
    constexpr int maxIteration{5};

    int outer{1};
    while (outer <= maxIteration)
    {

        int inner2{maxIteration - outer};
        while (inner2 > 0)
        {
            std::cout << filler << ' ';
            --inner2;
        }

        int inner{outer};
        while (inner > 0)
        {
            std::cout << inner-- << ' ';
        }

        std::cout << '\n';
        ++outer;
    }

    return 0;
}