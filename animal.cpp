#include <iostream>
#include <string_view>

enum class Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

constexpr std::string_view getAnimalName(const Animal &animal);
void printNumberOfLegs(const Animal &animal);

int main()
{
    printNumberOfLegs(Animal::cat);
    printNumberOfLegs(Animal::chicken);
    return 0;
}

constexpr std::string_view getAnimalName(const Animal &animal)
{
    using enum Animal;

    switch (animal)
    {
    case pig:
        return "Pig";

    case chicken:
        return "Chicken";

    case goat:
        return "Goat";

    case cat:
        return "Cat";

    case dog:
        return "Dog";

    case duck:
        return "Duck";

    default:
        return "???";
    }
}

void printNumberOfLegs(const Animal &animal)
{
    using enum Animal;

    short numerOfLegs{};
    std::string_view animalName{};

    switch (animal)
    {
    case pig:
        numerOfLegs = 4;
        animalName = getAnimalName(pig);
        break;

    case chicken:
        numerOfLegs = 2;
        animalName = getAnimalName(chicken);
        break;

    case goat:
        numerOfLegs = 4;
        animalName = getAnimalName(goat);
        break;

    case cat:
        numerOfLegs = 4;
        animalName = getAnimalName(cat);
        break;

    case dog:
        numerOfLegs = 4;
        animalName = getAnimalName(dog);
        break;

    case duck:
        numerOfLegs = 2;
        animalName = getAnimalName(duck);
        break;

    default:
        return;
    }

    std::cout << "A " << animalName << " has " << numerOfLegs << " legs.\n";
}