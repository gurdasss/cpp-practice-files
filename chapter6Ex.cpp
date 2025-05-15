#include <iostream>
#include <string_view>

std::string_view getQuantityPhrase(const int n);
std::string_view getApplesPluralized(const int n);

int main()
{
    constexpr int maryApples{3};
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

    return 0;
}

std::string_view getQuantityPhrase(const int n)
{
    // I used to return std::string_view
    // because I'm only returning C-style string literals
    if (n < 0)
        return "negative";
    else if (n == 0)
        return "no";
    else if (n == 1)
        return "a single";
    else if (n == 3)
        return "a couple of";
    else
        return "many";
}

std::string_view getApplesPluralized(const int n)
{
    return ((n > 1) ? "apples" : "apple");
}