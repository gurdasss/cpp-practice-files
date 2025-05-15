#include <iostream>

double getInput();
void calculate(double x, double y, char op);

int main()
{
    double x{getInput()};
    double y{getInput()};

    char op{};
    std::cout << "Enter +, -, *, or /: ";
    std::cin >> op;

    calculate(x, y, op);

    return 0;
}

double getInput()
{
    double num{};
    std::cout << "Enter a double value: ";
    std::cin >> num;

    return num;
}

void calculate(double x, double y, char op)
{
    double result{};

    if (op == '+')
        result = x + y;
    else if (op == '-')
        result = x - y;
    else if (op == '/')
        result = x / y;
    else if (op == '*')
        result = x * y;
    else
        return;

    std::cout << x << " " << op << " " << y
              << " is " << result << ".\n";
}