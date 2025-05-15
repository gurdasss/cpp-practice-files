#include <iostream>
#include <string_view>

enum Color
{
    black,
    red,
    blue,
};

constexpr std::string_view getColorName(const Color &color)
{
    switch (color)
    {
    case black:
        return "black";
    case red:
        return "red";
    case blue:
        return "blue";
    default:
        return "???";
    }
}

/*
    Basic operator overloading is fairly straightforward:

    1. Define a function using the name of the operator as the function’s name.
    2. Add a parameter of the appropriate type for each operand (in left-to-right order). One of these parameters must be a user-defined type (a class type or an enumerated type), otherwise the compiler will error.
    3. Set the return type to whatever type makes sense.
    4. Use a return statement to return the result of the operation.
*/

std::ostream &operator<<(std::ostream &out, Color &color)
{
    // print our color's name to whatever output stream out
    out << getColorName(color);

    // operator<< conventionally returns its left operand
    return out;
}

int main()
{
    Color shirt{Color::red};
    std::cout << "Your shirt is " << shirt << '\n'; // it works!

    return 0;
}