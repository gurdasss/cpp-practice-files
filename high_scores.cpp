// High Scores
// Demonstrates algorithms

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include <random>
#include <chrono>


using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	vector<int> scores;
	scores.push_back(1500);
	scores.push_back(3500);
	scores.push_back(7500);

	vector<int>::const_iterator iter;

	cout << "\nHigh Scores:\n";

	for (iter = scores.begin(); iter != scores.end(); ++iter)
	{
		cout << *iter << endl;
	}


	cout << "\nFinding a score.";
	int score;
	
	cout << "\nEnter a score to find: ";
	cin >> score;

	iter = find(scores.begin(), scores.end(), score);
	if (iter != scores.end())
	{
		cout << "Score found.\n";
	}
	else
	{
		cout << "Score not found.\n";
	}

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();


	cout << "\nRandomizing scores.\n";

	// somehow the below code is not running in my phone.

	//srand(static_cast<unsigned int>(time(0)));

	//random_shuffle(scores.begin(), scores.end());

	shuffle(scores.begin(), scores.end(), std::default_random_engine(seed));

	for (iter = scores.begin(); iter != scores.end(); ++iter)
	{
		cout << *iter << endl;
	}


	cout << "\nSorting scores.\n";
	sort(scores.begin(), scores.end());

	for (iter = scores.begin(); iter != scores.end(); ++iter)
	{
		cout << *iter << endl;
	}


	return 0;
}
