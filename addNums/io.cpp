#include <iostream>

int readNumber() {

  int input{};
  std::cout << "Enter an integer: ";
  std::cin >> input;

  return input;
}

void writeAnswer(int result) {
  std::cout << "The answer is " << result << '\n';
}
