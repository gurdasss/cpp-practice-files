#include <iostream>
#include <string>
#include <string_view>

std::string getFullName(short i);
short getAgeFor(std::string_view person);
void printOlder(std::string_view person1, short age1,
                std::string_view person2, short age2);

int main()
{
    const std::string person1{getFullName(1)};
    const short age1{getAgeFor(person1)};

    const std::string person2{getFullName(2)};
    const short age2{getAgeFor(person2)};

    printOlder(person1, age1, person2, age2);

    return 0;
}

std::string getFullName(short i)
{
    std::cout << "Enter the name of person #" << i << ": ";
    std::string fullName{};
    std::getline(std::cin >> std::ws, fullName);

    return fullName;
}

short getAgeFor(std::string_view person)
{
    std::cout << "Enter the age of " << person << ": ";
    short age{};
    std::cin >> age;

    return age;
}

void printOlder(std::string_view person1, short age1,
                std::string_view person2, short age2)
{
    if (age1 > age2)
    {
        std::cout << person1 << " (age " << age1 << ") is older than "
                  << person2 << " (age " << age2 << ")\n";
    }
    else if (age2 > age1)
    {
        std::cout << person2 << " (age " << age2 << ") is older than "
                  << person1 << " (age " << age1 << ")\n";
    }
}