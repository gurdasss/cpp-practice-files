#include <iostream>

struct Foo
{
    int id{};
};

struct Goo
{
    // a static member variable
    // shared across all the instantiated
    // objects of Goo class type

    // static member variable declaration

    static int id;
};

// static member variable definition (and initialization)

int Goo::id{};

int main()
{
    Foo foo1{};
    Foo foo2{};

    std::cout << "NON-STATIC MEMBER VARIABLE\n";

    std::cout << "foo1.id Value: " << foo1.id << '\n';
    std::cout << "foo1.id Address: " << &foo1.id << '\n';

    std::cout << "foo2.id Value: " << foo2.id << '\n';
    std::cout << "foo2.id Address: " << &foo2.id << '\n';

    Goo::id = 2;

    // static member variables can be accessed
    // without instantiating an object

    Goo goo1{};
    Goo goo2{};

    std::cout << "STATIC MEMBER VARIABLE\n";

    std::cout << "goo1.id Value: " << goo1.id << '\n';
    std::cout << "goo1.id Address: " << &goo1.id << '\n';

    std::cout << "goo2.id Value: " << goo2.id << '\n';
    std::cout << "goo2.id Address: " << &goo2.id << '\n';

    return 0;
}