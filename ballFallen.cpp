#include <iostream>

double getTowerHeight();
double calculateRemainingDistance(int seconds, double towerHeight);
void printRemainingDistance(int seconds, double towerHeight);

int main()
{
    double towerHeight{getTowerHeight()};

    printRemainingDistance(0, towerHeight);
    printRemainingDistance(1, towerHeight);
    printRemainingDistance(2, towerHeight);
    printRemainingDistance(3, towerHeight);
    printRemainingDistance(4, towerHeight);
    printRemainingDistance(5, towerHeight);

    return 0;
}

double getTowerHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double towerHeight{};
    std::cin >> towerHeight;

    return towerHeight;
}

void printRemainingDistance(int seconds, double towerHeight)
{
    double remainingDistance{calculateRemainingDistance(seconds, towerHeight)};

    std::cout << "At " << seconds << " seconds, ";

    if (remainingDistance < 0.0)
        std::cout << "the ball is on the ground.\n";
    else
        std::cout << "the ball is at height: " << remainingDistance
                  << "  meters" << '\n';
}

double calculateRemainingDistance(int seconds, double towerHeight)
{
    constexpr double gravity{9.8};

    double fallen{gravity * ((seconds * seconds) / 2.0)};
    return towerHeight - fallen;
}