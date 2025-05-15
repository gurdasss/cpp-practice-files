#include <iostream>

int main()
{
    char currentAlpha{'a'};

    while (currentAlpha <= 'z')
    {
        std::cout << currentAlpha << ": " << static_cast<int>(currentAlpha) << '\n';
        currentAlpha++;
    }
    return 0;
}