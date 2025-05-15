#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	const short ROWS = 3;
	const short COLUMNS = 3;

	char board[ROWS][COLUMNS] = {

		{ 'O', 'X', 'O' },
		{ ' ', 'X', 'X' },
		{ 'X', 'O', 'O' }

	};

	cout << "Here’s the tic-tac-toe board:\n";

	for (unsigned short i = 0; i < ROWS; ++i)
	{

		for (unsigned short j = 0; j < COLUMNS; ++j)
		{
			cout << board[i][j];
		}

		cout << endl;

	}

	cout << "\n’X’ moves to the empty location.\n\n";

	board[1][0] = 'X';
	cout << "Now the tic-tac-toe board is:\n";


	for (unsigned short i = 0; i < ROWS; ++i)
	{

		for (unsigned short j = 0; j < COLUMNS; ++j)
		{
			cout << board[i][j];
		}

		cout << endl;

	}

	cout << "\n’X’ wins!";

	return 0;
}
