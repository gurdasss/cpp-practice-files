#include <iostream>

// class forward declaration

class Vector3D;

class Point3D
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point3D(double x, double y, double z)
        : m_x{x}, m_y{y}, m_z{z}
    {
    }

    void print() const
    {
        std::cout << "Point(" << m_x << ", " << m_y << ", " << m_z << ")\n";
    }

    void moveByVector(const Vector3D &v);
};

class Vector3D
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Vector3D(double x, double y, double z)
        : m_x{x}, m_y{y}, m_z{z}
    {
    }

    void print() const
    {
        std::cout << "Vector(" << m_x << ", " << m_y << ", " << m_z << ")\n";
    }

    // making Point3D a friend class of Vector3D
    // friend class Point3D;

    // making Point3D::moveByVector(const Vector3D &v) member function
    // a friend of Vector3D
    friend void Point3D::moveByVector(const Vector3D &v);
};

void Point3D::moveByVector(const Vector3D &v)
{
    m_x += v.m_x;
    m_y += v.m_y;
    m_z += v.m_z;
}

int main()
{
    Point3D p{1.0, 2.0, 3.0};
    Vector3D v{2.0, 2.0, -3.0};

    p.print();
    p.moveByVector(v);
    p.print();

    return 0;
}