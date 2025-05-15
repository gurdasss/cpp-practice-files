#include <iostream>

int main() {
  int num1{};
  int num2{};

  std::cout << "Enter two integers: ";

  std::cin >> num1 >> num2;

  std::cout << "Sum of " << num1 << " and " << num2 << " is " << (num1 + num2)
            << '\n';
  std::cout << "Subtraction of " << num1 << " and " << num2 << " is "
            << (num1 - num2) << '\n';

  return 0;
}
