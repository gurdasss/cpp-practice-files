#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

int main(void)
{
    string firstName = "???";

    string friendName = "???";
    char friendSex = 0;
    short age = -1;

    cout << "Enter the name of the person you want to write to: ";
    cin >> firstName;

    cout << "Dear, " << firstName << endl;

    cout << "\tHow are you? I'm doing great!!\n"
         << endl;

    cout << "Enter the name of your mutual friend: ";
    cin >> friendName;

    cout << "Have you seen " << friendName << " lately?\n"
         << endl;

    cout << "Enter your friend's sexuality (MALE (m) or FEMALE (f)): ";
    cin >> friendSex;

    cout << "If you see " << friendName << " please ";

    if (friendSex == 'm')
        cout << "ask him to call me.";
    else if (friendSex == 'f')
        cout << "ask her to call me.";

    cout << endl;

    cout << "Enter the age of the person you're writing to: ";
    cin >> age;

    if (age > 0 && age < 110)
    {
        cout << "I hear you just had a birthday and ";
        cout << "you're " << age << " years old." << endl;

        if (age < 12)
            cout << "Next year you'll be age+1." << endl;
        else if (age == 17)
            cout << "Next year you'll be able to vote." << endl;
        else if (age > 70)
            cout << "I hope you're enjoying retirement." << endl;
    }
    else
        cout << "You're kidding!!" << endl;

    cout << "Your sincerely,\n"
         << endl;
    cout << "Gurdas Satwani" << endl;
    return 0;
}