#include "Random.h"

#include <cassert> // for assert
#include <limits>  // for std::numeric_limits
#include <iostream>

namespace InputBufferUtilities
{
    void ignoreLine()
    {
        /*
        To ignore all characters up to the next ‘\n’

        returns the largest value that can be stored in a variable of type std::streamsize

        Passing this value to std::cin.ignore() causes it to disable the count check.
        */
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // returns true if extraction failed, false otherwise
    bool clearFailedExtraction()
    {
        // Check for failed extraction
        if (!std::cin) // If the previous extraction failed
        {
            if (std::cin.eof()) // If the stream was closed
            {
                std::exit(0); // Shut down the program now
            }

            // Let's handle the failure
            std::cin.clear(); // Put us back in 'normal' operation mode
            ignoreLine();     // And remove the bad input

            return true;
        }

        return false;
    }

    // returns true if std::cin has unextracted input on the current line, false otherwise
    bool hasUnextractedInput()
    {
        return !std::cin.eof() && std::cin.peek() != '\n';
    }

} // namespace InputBufferUtilities

void greet(const int lowerBound, const int upperBound, const int guesses);
int getGuess(int guessCount);
char getUserChoice();

void playGame(const int lowerBound, const int upperBound, const int guesses);
char evaluateGuess(const int secretNum, const int recentGuess);
void printEvaluationResult(const char evaluationStatus);

int main()
{
    /*
        only start of the new game:
        greet()
        generateSecretNum()
        restRemainingGuessChance()

        while playing the game:
        getGuess()
        evaluateGuess()
        printEvaluationResult()
        updateRemainingGuessChance()

        once the game is over:
        ask user if they want to play again

    */

    playGame(1, 100, 7);

    return 0;
}

// TESTED
void playGame(const int lowerBound, const int upperBound, const int guesses)
{
    while (true)
    {
        // Initializing:
        greet(lowerBound, upperBound, guesses);
        const int secretNum(Random::get(lowerBound, upperBound));
        int remainingChances{1};

        std::cout << secretNum << '\n';

        // Playing Stage:
        while (remainingChances <= guesses)
        {
            int recentGuess{getGuess(remainingChances)};

            char evaluationStatus{evaluateGuess(secretNum, recentGuess)};

            printEvaluationResult(evaluationStatus);

            if (evaluationStatus == 'E')
                break;
            if (remainingChances == guesses)
            {
                std::cout << "Sorry, you lose. The correct number was "
                          << secretNum << ".\n";
                break;
            }

            remainingChances++;
        }

        // Once the game is over:
        switch (getUserChoice())
        {
        case 'y':
            continue;
        case 'n':
            return;
        }
    }
}

// TESTED
void printEvaluationResult(const char evaluationStatus)
{
    switch (evaluationStatus)
    {
    case 'H':
        std::cout << "Your guess is too high.\n";
        return;
    case 'L':
        std::cout << "Your guess is too low.\n";
        return;
    case 'E':
        std::cout << "Correct! You win!\n";
        return;

    default:
        std::cout << "There is something funny in"
                     " printEvaluationResult()\n";
    }
}

// TESTED
char evaluateGuess(const int secretNum, const int recentGuess)
{
    /*
        'H' meaning "High" : secretNum > recentGuess
        'L' meaning "Low"  : secretNum < recentGuess
        'E' meaning "Equal": secretNum = recentGuess
    */

    if (secretNum > recentGuess)
        return 'L';
    else if (secretNum < recentGuess)
        return 'H';
    else
        return 'E';
}

// TESTED
void greet(const int lowerBound, const int upperBound, const int guesses)
{

    std::cout << "Let's play a game. I'm thinking of a number between ";
    std::cout << lowerBound << " and " << upperBound << ".\n";

    std::cout << "You have " << guesses << " tries to guess what it is.\n";
}

// TESTED
int getGuess(int guessCount)
{

    while (true)
    {

        std::cout << "Guess #" << guessCount << ": ";

        int guess{};
        std::cin >> guess;

        // assert(!InputBufferUtilities::hasUnextractedInput() && "Has some unextracted input!!");

        if (InputBufferUtilities::clearFailedExtraction())
        {
            std::cout << "This game will only accept integers!!\n";
            continue;
        }

        return guess;
    }
}

// TESTED
char getUserChoice()
{
    while (true)
    {
        std::cout << "Would you like to play again (y/n)? ";
        char userChoice{};
        std::cin >> userChoice;

        if (InputBufferUtilities::clearFailedExtraction())
        {
            std::cout << "Invalid input! Please enter again!\n";
            continue;
        }

        switch (userChoice)
        {
        case 'y':
            return 'y';
        case 'n':
            return 'n';
        default:
            std::cout << "Please only enter y(es) or n(o).\n";
        }
    }
}