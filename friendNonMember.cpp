#include <iostream>

class Foo
{
public:
    void add(int num) { m_num += num; }

    friend void print(const Foo &foo);

private:
    int m_num{};
};

// Because print() is defined as a friend, it is
//  instead treated as a non-member function

void print(const Foo &foo) { std::cout << foo.m_num << '\n'; }

int main()
{
    Foo foo1{};

    return 0;
}