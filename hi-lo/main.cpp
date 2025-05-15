#include "Random.h"
#include <iostream>

void greet(int lowerBound, int upperBound, int guesses);
int getGuess(int guessCount);
char getUserChoice();

int main()
{
    constexpr int lowerBound{1};
    constexpr int upperBound{100};
    constexpr int guesses{7};

    while (true)
    {
        greet(lowerBound, upperBound, guesses);
        int secretNum{Random::get(lowerBound, upperBound)};
        int remainingGuess{guesses};

        std::cout << secretNum << '\n';

        while (true)
        {

            int userGuess{getGuess(remainingGuess)};

            if (remainingGuess <= 0)
            {
                std::cout << "Sorry, you lose. The correct number was "
                          << secretNum << ".\n";
                break;
            }

            if (secretNum == userGuess)
            {
                std::cout << "Correct! You win!\n";
                break;
            }
            else if (secretNum < userGuess)
                std::cout << "Your guess is too low.\n";
            else
                std::cout << "Your guess is too high.\n";

            remainingGuess--;
        }

        char userChoice = getUserChoice();

        if (userChoice == 'y')
        {
            // clear the screen
            continue;
        }
        else if (userChoice == 'n')
        {
            std::cout << "Thank you for playing.\n";
            break;
        }
    }

    return 0;
}

void greet(const int lowerBound, const int upperBound, const int guesses)
{
    std::cout << "Let's play a game. I'm thinking of a number between ";
    std::cout << lowerBound << " and " << upperBound << ".\n";

    std::cout << "You have " << guesses << " tries to guess what it is.\n";
}

int getGuess(int guessCount)
{
    std::cout << "Guess #" << guessCount << ": ";

    int guess{};
    std::cin >> guess;

    return guess;
}

char getUserChoice()
{
    while (true)
    {
        std::cout << "Would you like to play again (y/n)? ";
        char userChoice{};
        std::cin >> userChoice;

        switch (userChoice)
        {
        case 'y':
            return 'y';
        case 'n':
            return 'n';
        default:
            std::cout << "Invalid choice! Please enter again!\n";
            break;
        }
    }
}