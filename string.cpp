#include <iostream>
#include <string> // std::string & std::getline

int main()
{
    std::cout << "Enter your full name: ";
    std::string fullName{};
    std::getline(std::cin >> std::ws, fullName);

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    int result{};
    // std::string::length() returns an unsigned value
    // we need to explicitly convert its value
    // to signed
    result = age + static_cast<int>(fullName.length());
    std::cout << "Your age + length of name is: " << result << '\n';
    return 0;
}