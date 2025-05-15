#include <iostream>

int getInt();
char getOperator();
int getResult(int a, int b, char op);

int main()
{
    int x{getInt()};
    int y{getInt()};
    char op{getOperator()};

    int result{getResult(x, y, op)};

    std::cout << x << op << y << " = " << result << '\n';
    return 0;
}

int getInt()
{
    std::cout << "Enter an integer: ";
    int num{};
    std::cin >> num;

    return num;
}

char getOperator()
{
    std::cout << "+, -, *, /\n";
    std::cout << "Enter an operator: ";
    char op{};
    std::cin >> op;

    return op;
}

int getResult(int a, int b, char op)
{
    int result{};
    switch (op)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    default:
        return 1;
    }

    return result;
}