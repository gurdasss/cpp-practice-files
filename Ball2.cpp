#include <iostream>
#include <string>
#include <string_view>

class Ball
{
public:
    // Delegate to second overloaded constructor
    Ball(double radius)
        : Ball{"black", radius}
    {
    }

    Ball(std::string_view color = "black", double radius = 10.0)
        : m_color{color},
          m_radius{radius}
    {
        std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
    }

private:
    std::string m_color{"black"};
    double m_radius{10.0};
};

int main()
{
    Ball def{};
    Ball blue{"blue"};
    Ball twenty{20.0};
    Ball blueTwenty{"blue", 20.0};

    return 0;
}