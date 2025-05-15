#include <iostream>
#include <limits>
#include <optional>
#include <string>
#include <string_view>

enum Pet
{
    cat,   // 0
    dog,   // 1
    pig,   // 2
    whale, // 3
};

constexpr std::string_view getPetName(const Pet &pet)
{
    switch (pet)
    {
    case cat:
        return "cat";
    case dog:
        return "dog";
    case pig:
        return "pig";
    case whale:
        return "whale";
    default:
        return "???";
    }
}

constexpr std::optional<Pet> getPetFromString(std::string_view sv)
{
    if (sv == "cat")
        return cat;
    if (sv == "dog")
        return dog;
    if (sv == "pig")
        return pig;
    if (sv == "whale")
        return whale;

    return std::nullopt;
}

/*
    Basic operator overloading is fairly straightforward:

    1. Define a function using the name of the operator as the function’s name.
    2. Add a parameter of the appropriate type for each operand (in left-to-right order). One of these parameters must be a user-defined type (a class type or an enumerated type), otherwise the compiler will error.
    3. Set the return type to whatever type makes sense.
    4. Use a return statement to return the result of the operation.
*/

std::istream &operator>>(std::istream &in, Pet &pet)
{
    std::string s{};
    in >> s; // get input string from user

    std::optional<Pet> match{getPetFromString(s)};

    // if we found a match
    if (match)
    {
        // dereference std::optional to get matching enumerator
        pet = *match;
        return in;
    }

    // We didn't find a match, so input must have been invalid
    // so we will set input stream to fail state
    in.setstate(std::ios_base::failbit);

    // On an extraction failure, operator>> zero-initializes fundamental types
    // Uncomment the following line to make this operator do the same thing
    pet = {};

    return in;
}

int main()
{
    std::cout << "Enter a pet: cat, dog, pig, or whale: ";
    Pet pet{};
    std::cin >> pet;

    if (std::cin) // if we found a match
        std::cout << "You chose: " << getPetName(pet) << '\n';
    else
    {
        std::cin.clear(); // reset the input stream to good
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Your pet was not valid\n";
    }

    return 0;
}