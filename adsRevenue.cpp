#include <iostream>

struct RevenueData
{
    short numAdsWatched{};
    float clickAdsPersentage{};
    double avgEarning{};
};

std::istream &operator>>(std::istream &in, RevenueData &revenueData)
{
    std::cout << "Enter number of ads watched: ";
    in >> revenueData.numAdsWatched;

    std::cout << "Enter the percentage of user clicked on ads: ";
    in >> revenueData.clickAdsPersentage;

    std::cout << "Enter the average earning: ";
    in >> revenueData.avgEarning;

    return in;
}

std::ostream &operator<<(std::ostream &out, const RevenueData &revenueData)
{
    out << "Number of ads watched: " << revenueData.numAdsWatched << '\n';
    out << "Percentage of user clicked on ads: "
        << revenueData.clickAdsPersentage << '\n';

    out << "Average earning: " << revenueData.avgEarning << '\n';

    out << "How much you made today: "
        << revenueData.numAdsWatched *
               revenueData.clickAdsPersentage *
               revenueData.avgEarning
        << '\n';

    return out;
}

int main()
{

    RevenueData day1{};

    std::cin >> day1;
    std::cout << day1;

    return 0;
}