#include <iostream>
#include <string>

template <typename T, typename U, typename V>
class Triad
{
public:
    // When we define a member function inside the class definition,
    // the template parameter declaration belonging to the class applies
    Triad(const T &x, const U &y, const V &z)
        : m_x{x},
          m_y{y},
          m_z{z}
    {
    }

    const T &first() const { return m_x; }
    const U &second() const { return m_y; }
    const V &third() const { return m_z; }

    void print() const;

private:
    T m_x{};
    U m_y{};
    V m_z{};
};

// When we define a member function outside the class definition,
// we need to resupply a template parameter declaration
template <typename T, typename U, typename V>
void Triad<T, U, V>::print() const
{
    std::cout << '[';
    std::cout << m_x << ", ";
    std::cout << m_y << ", ";
    std::cout << m_z;
    std::cout << ']';
}

int main()
{
    Triad<int, int, int> t1{1, 2, 3};
    t1.print();
    std::cout << '\n';
    std::cout << t1.first() << '\n';

    using namespace std::literals::string_literals;
    const Triad t2{1, 2.3, "Hello"s};
    t2.print();
    std::cout << '\n';

    return 0;
}