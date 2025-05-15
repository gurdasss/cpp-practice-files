#include <iostream>

int main()
{
    char ch{};
    std::cout << "Enter a character: ";
    std::cin >> ch;

    int chASCII{ch};

    // explicit conversion
    std::cout << "You entered \'" << ch << "\',"
              << " which has ASCII code " << static_cast<int>(ch) << ".\n";

    // implicit conversion
    std::cout << "You entered \'" << ch << "\',"
              << " which has ASCII code " << chASCII << ".\n";
    return 0;
}