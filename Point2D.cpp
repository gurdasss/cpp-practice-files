#include <iostream>
#include <cmath> // std::sqrt()

class Point2D
{
public:
    // Compiler won't generate an implicit
    // default constructor if an user-defined
    // constructor already exist
    Point2D() = default;
    Point2D(double x, double y)
        : m_x{x}, m_y{y}
    {
    }

    void print() const
    {
        std::cout << "Point(" << m_x << ", " << m_y << ")\n";
    }

    double distanceTo(const Point2D &point) const
    {
        return std::sqrt(std::pow(m_x - point.m_x, 2) +
                         std::pow(m_y - point.m_y, 2));
    }

private:
    double m_x{};
    double m_y{};
};

int main()
{
    Point2D first{};
    Point2D second{3.0, 4.0};

    // Point2d third{ 4.0 }; // should error if uncommented

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}