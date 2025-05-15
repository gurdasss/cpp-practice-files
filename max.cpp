#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

int main()
{
    /*
    A function template is only instantiated the first time a function call is made in each translation unit. Further calls to the function are routed to the already instantiated function.
    */
    std::cout << max(5, 6) << '\n';
    std::cout << max(6.7, 5.6) << '\n';
    std::cout << max('k', 'y') << '\n';
    return 0;
}