#include <iostream>

int getInt(short i);

int main()
{
    int smaller{getInt(1)};
    int larger{getInt(2)};

    if (smaller > larger)
    {
        std::cout << "Swapping the values:\n";

        int temp{larger};

        larger = smaller;
        smaller = temp;
    }

    std::cout << "The smaller value is " << smaller << '\n';
    std::cout << "The larger value is " << larger << '\n';

    return 0;
}

int getInt(short i)
{
    std::cout << "Enter an integer #" << i << ": ";
    int num{};
    std::cin >> num;

    return num;
}