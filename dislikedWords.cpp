#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;

using std::vector;
using std::string;

int main()
{
	string dislikeWord = "gay";

	cout << "Enter a sentence:\n" << endl;

	for(string temp; cin >> temp; )
	{
		if (temp == dislikeWord)
			cout << "BLEEP" << endl;
		else
			cout << temp << endl;
	}

	
	return 0;

}
