#include <iostream>

class Point3D
{
    // all the data members are private by default
    int m_x{};
    int m_y{};
    int m_z{};

    // Did'nt set it to const member function
    // because it will directly violate
    // the const-ness of const object of Point3D type
public:
    void setValues(int x, int y, int z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    // This const member function doesn't
    // change the value of any private data members
    void print() const
    {
        std::cout << "<" << m_x << ", "
                  << m_y << ", "
                  << m_z << ">\n";
    }

    bool isEqual(const Point3D &point3d) const
    {
        return (m_x == point3d.m_x &&
                m_y == point3d.m_y &&
                m_z == point3d.m_z);
    }
};

int main()
{
    Point3D point1{};
    point1.setValues(1, 2, 3);

    Point3D point2{};
    point2.setValues(1, 2, 3);

    std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

    Point3D point3{};
    point3.setValues(3, 4, 5);

    std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";

    return 0;
}