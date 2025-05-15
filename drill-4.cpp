#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::vector;

using std::sort;

int main()
{

	vector<string> validUnits = {"cm", "m", "in", "ft"};
	double smallest = 0, largest = 0;

	double inputNum = -1;
	string inputUnit = "";

	constexpr double differ = 1.0/100;
	double currentDiffer = 0;

	double conversionResult = 0;
	string conversionUnit = "m";

	double totalSum = 0;
	vector<double> userInputs;

	while (cin >> inputNum)
	{
		conversionResult = inputNum / 100; // cm -> m
		totalSum += conversionResult;
		userInputs.push_back(conversionResult);

		// if (inputUnit == validUnits[0])
		// {
		// 	conversionResult = inputNum / 100; // cm -> m
		// 	conversionUnit = validUnits[1];	   // m
		// }
		// else if (inputUnit == validUnits[1])
		// {
		// 	conversionResult = inputNum * 100; // m -> cm
		// 	conversionUnit = validUnits[0];	   // cm
		// }
		// else if (inputUnit == validUnits[2])
		// {
		// 	conversionResult = inputNum * 2.54; // in -> cm
		// 	conversionUnit = validUnits[0];		// cm
		// }
		// else if (inputUnit == validUnits[3])
		// {
		// 	conversionResult = inputNum * 12; // ft -> in
		// 	conversionUnit = validUnits[2];	  // in
		// }
		// else
		// {
		// 	cout << "Please, enter a valid unit.\n"
		// 		 << "[cm, m, in, ft]" << endl;
		// }

		// cout << inputNum << inputUnit << " == " << conversionResult << conversionUnit << endl;

		if (inputNum > largest)
		{
			smallest = largest;
			largest = inputNum;
		}
		else if (inputNum < largest)
		{
			smallest = inputNum;
		}

		currentDiffer = largest - smallest;

		if (currentDiffer < differ)
			cout << "the numbers are almost equal" << endl;
	}

	cout << "Here are all the values you'd entered so far:" << endl;

	for (double value : userInputs)
		cout << value << endl;

	cout << "The smallest value so far: " << smallest << endl;
	cout << "The largest value so  far: " << largest << endl;

	cout << "Total sum = " << totalSum << conversionUnit << endl;
	return 0;
}
