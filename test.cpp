#include <iostream>

int main()
{
	// pointer to a const value
	const char *str{"Hello World!"};

	std::cout << "\"Hello World!\": " << &"Hello World!" << '\n';
	std::cout << "str: " << &str << '\n';
	std::cout << "str: " << str << '\n';

	return 0;
}