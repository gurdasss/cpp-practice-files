#include <vector>

int main()
{
    // compiler will automatically will
    // be able to deduce std::vector nums
    // types using initializer list values
    // Class Template Argument Deduction (CTAD)
    std::vector nums{1, 4, 9, 16, 25};
    return 0;
}