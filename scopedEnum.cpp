#include <iostream>
#include <utility>

enum class Color
{
    red,
    blue,
};

int main()
{
    // EVERYTHING IS WORKING
    using enum Color;

    Color fruit{};

    std::cout << std::to_underlying(fruit) << '\n';

    std::cout << static_cast<int>(fruit) << '\n';

    return 0;
}