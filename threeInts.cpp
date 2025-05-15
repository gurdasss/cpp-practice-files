#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    short a = 0, b = 0, c = 0;

    cout << "Enter three integers [separated by space]: ";
    cin >> a >> b >> c;

    if (a == b)
    {
        cout << a << ", " << b << ", ";
        // if (a < c)
        //     cout <<
    }
    if (a == c)
        cout << a << ", " << c << ", ";
    if (b == c)
        cout << b << ", " << c << ", ";

    return 0;
}
