#include <iostream>

int getInteger() {
  std::cout << "Enter an integer: ";
  int input{};
  std::cin >> input;

  return input;
}
