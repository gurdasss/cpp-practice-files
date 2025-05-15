#include <iostream>
#include <string>

struct Employee
{
    std::string name{};
    short age{};
    float salary{};
};

std::ostream &operator<<(std::ostream &out, const Employee &emp)
{
    out << "Name: " << emp.name
        << " Age: " << emp.age
        << " Salary: " << emp.salary;

    return out;
}

int main()
{
    Employee joe{"Joe", 24, 2500};

    std::cout << joe << '\n';

    std::cout << Employee{"John", 24, 2500} << '\n';

    return 0;
}