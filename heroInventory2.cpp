// Hero's inventory
// but this time with vector and iterators

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(void)
{
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	vector<string>::iterator myIterator;
	vector<string>::const_iterator iter;

	cout << "Your items:\n";

	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << "\nYou trade your sword for a battle axe.";
	// inventory[0] = "battle axe";
	// the above code is dangerous and it will
	// crash the program.
	
	myIterator = inventory.begin();
	*myIterator = "battle axe";

	cout << "Your items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		cout << *iter << endl;
	}

	// cout << "The item name '" << inventory[0] << "' has ";
	cout << "The item name '" << *myIterator << "' has ";
	cout << (*myIterator).size() << " letters in it." << endl;

	// just an experiment
	cout << "The item name '" << *(myIterator + 1) << "' has \n\n";

	// another way to use myIterator

	cout << "The item name '" << *myIterator << "' has ";
	cout << myIterator->size() << " letters in it." << endl;

	// just an experiment
	cout << (myIterator + 1)->size() << " letters in it.\n\n";

	cout << "\nYou recover a crossbow from a slain enemy.";
	inventory.insert(inventory.begin(), "crossbow");

	cout << "Your items:\n\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << "\nYour armor is destroyed in a fierce battle.";

	inventory.erase((myIterator + 2));
	cout << "Your items:\n\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		cout << *iter << endl;
	}



	return 0;
}
