#include <iostream>

template <typename T>
struct Triad
{
    T x{};
    T y{};
    T z{};
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Triad<T> &triad)
{

    out << '[' << triad.x
        << ", " << triad.y
        << ", " << triad.z
        << ']';

    return out;
}

template <typename T>
void print(const Triad<T> &triad)
{
    std::cout << '[' << triad.x
              << ", " << triad.y
              << ", " << triad.z
              << ']';
}

int main()
{
    std::cout << Triad{1, 2, 3} << '\n';
    print(Triad{1, 2, 3});
    std::cout << Triad{5.6, 9.8, 2.2} << '\n';
    return 0;
}