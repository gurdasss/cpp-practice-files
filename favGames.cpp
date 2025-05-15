// A program that dynamically allows the user to add their favorite games

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::find;
using std::sort;
using std::string;
using std::vector;

int main(int argc, char const *argv[])
{
    vector<string> gameList;
    vector<string>::const_iterator constIter;

    bool isRunning = true;
    string userStr;
    char choice;

    while (isRunning)
    {
        cout << "FAVORITE GAMES" << endl;
        cout << "1. ADD A GAME" << endl;
        cout << "2. REMOVE A GAME" << endl;
        cout << "3. LIST ALL GAMES" << endl;
        cout << "4. QUIT" << endl;

        cout << "[1, 2, 3, 4]" << endl;
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice)
        {

        case '1':
            cout << "ENTER YOUR GAME NAME: ";
            cin >> userStr;

            gameList.push_back(userStr);

            sort(gameList.begin(), gameList.end());

            cout << "GAME WAS ADDED SUCCESSFULLY" << endl;

            break;

        case '2':
            cout << "HERE ARE YOUR FAVORITE GAMES:" << endl;
            for (constIter = gameList.begin(); constIter != gameList.end(); ++constIter)
            {
                cout << *constIter << endl;
            }

            cout << "ENTER YOUR GAME NAME: ";
            cin >> userStr;

            constIter = find(gameList.begin(), gameList.end(), userStr);

            if (constIter != gameList.end())
            {
                gameList.erase(constIter);
                cout << "GAME WAS SUCCESSFULLY REMOVED" << endl;
            }

            break;

        case '3':
            cout << "HERE ARE YOUR FAVORITE GAMES:" << endl;
            for (constIter = gameList.begin(); constIter != gameList.end(); ++constIter)
            {
                cout << *constIter << endl;
            }

            break;

        case '4':
            isRunning = false;
            break;

        default:
            cout << "PLEASE ENTER A VALID INPUT" << endl;
            break;
        }
    }

    return 0;
}
