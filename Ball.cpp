#include <iostream>
#include <string>
#include <string_view>

class Ball
{
public:
    Ball(std::string_view color, float radius)
        : m_color{color}, // member initializer list
          m_radius{radius}
    {
        // Constructor's body is often empty
    }

    /*
    It is okay to return a (const) lvalue reference to a data member. The implicit object (containing the data member) still exists in the scope of the caller after the function returns, so any returned references will be valid.
    */
    const std::string &getColor() const { return m_color; }
    float getRadius() const { return m_radius; }

private:
    std::string m_color{};
    float m_radius{};
};

void print(const Ball &ball)
{
    std::cout << "Ball(" << ball.getColor()
              << ", " << ball.getRadius() << ")\n";
}

int main()
{
    Ball blue{"blue", 10.0};
    print(blue);

    Ball red{"red", 12.0};
    print(red);

    return 0;
}