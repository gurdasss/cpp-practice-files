#include <iostream>

template <typename T>
struct Pair
{
    T first{};
    T second{};
};

template <typename T>
constexpr T max(Pair<T> pair)
{
    return (pair.first < pair.second) ? pair.second : pair.first;
}

int main()
{
    Pair p1{1, 2};
    std::cout << p1.first << ' ' << p1.second << '\n';
    std::cout << max(p1) << '\n';

    Pair p2{2.5, 6.5};
    std::cout << p2.first << ' ' << p2.second << '\n';
    std::cout << max(p2) << '\n';

    return 0;
}