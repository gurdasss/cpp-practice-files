#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> nums{4, 3, 2, 1, 0};

    auto itr{nums.begin()}; // [4] 3 2 1 0
    std::cout << *itr << '\n';

    ++itr; // 4 [3] 2 1 0
    std::cout << *itr << '\n';

    ++itr; // 4 3 [2] 1 0
    std::cout << *itr << '\n';

    ++itr; // 4 3 2 [1] 0
    std::cout << *itr << '\n';

    ++itr; // 4 3 2 1 [0]
    std::cout << *itr << '\n';

    ++itr; // 4 3 2 1 0 []
    // don't dereference itr now as it's pointing to
    // either null or ???
    // std::cout << *itr << '\n';
    std::cout << std::boolalpha;
    std::cout << (itr == nums.cend()) << '\n';

    return 0;
}