#include <iostream>
#include <vector>

void getIntInputs(std::vector<int> &inputs, int noOfInputs);

int main()
{

    constexpr int noOfInputs{3};
    // construct a std::vector with 3
    // elements of type int
    // direct initialization
    std::vector<int> nums(noOfInputs);

    getIntInputs(nums, noOfInputs);

    int sum{0};
    int product{1};

    for (int num : nums)
    {
        sum += num;
        product *= num;
    }

    std::cout << "The sum is: " << sum << '\n';
    std::cout << "The product is: " << product << '\n';

    return 0;
}

void getIntInputs(std::vector<int> &inputs, int noOfInputs)
{
    std::cout << "Enter " << noOfInputs << " integers: ";

    // assign user entered values to each element
    // of the container
    // we need to assign those values to the elements
    // itself not its copies
    for (int &input : inputs)
        std::cin >> input;
}
