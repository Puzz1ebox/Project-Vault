/**
*
*Assignment #2
*
*Academic Integrity Statement: I certify that, while others may have assisted me in
brainstorming, debugging and validating this program, the program itself is my own
work. I understand that submitting code which is the work of other individuals is a
violation of the course Academic Integrity Policy and may result in a zero credit for
the assignment, or course failure and a report to the Academic Dishonesty Board. I
also understand that if I knowingly give my original work to another individual that
it could also result in a zero credit for the assignment, or course failure and a
report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines
at:
https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-inte
grity-procedural-guidelines
*
*Student Name: Raymond A. Bailey
*
*PSU user ID: XXX6548
*
*PSU email: rab6548@psu.edu
*
*CMPSC122 Fall 2022
*
*Due Time: 11:59PM, Wednesday, September 07, 2022
*
*Time of Last Modification: 11:13AM, Wednesday, September 07, 2022
*Description: Allows a player or a computer to play a guessing game, where the objective is to guess a randomly generated number between 10 - 99
*
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>

using namespace std;

int DetermineSum(int number);
void PersonPlaysGame();
void ComputerPlaysGame();

int main()
{

    while (true)
    {
        auto decision = 'a';

        cout << "Would you like to (p)lay or watch the (c)omputer play or (e)xit?" << endl;
        cin >> decision;

        if (decision == 'p')
        {
            PersonPlaysGame();
        }
        else if (decision == 'c')
        {
            ComputerPlaysGame();
        }
        else if (decision == 'e')
        {
            cout << "Exiting Program..." << endl;
            return 0;
        }
        else
        {
            cout << "That is not a valid decision. Please try again." << endl;
        }

    }
    return 0;
}

/* Standard Output
 *
C:\Users\Puzz1ebox\CLionProjects\Proj2\cmake-build-debug\Proj2.exe
Would you like to (p)lay or watch the (c)omputer play or (e)xit?
p
Enter your guess (must be between 10 and 99).
10
Your guess is incorrect. Try again.
Enter your guess (must be between 10 and 99).
11
Your guess is incorrect. Try again.
Enter your guess (must be between 10 and 99).
12
Your guess is incorrect. Try again.
Enter your guess (must be between 10 and 99).
13
Your guess is incorrect. Try again.
Enter your guess (must be between 10 and 99).
14
Your guess is incorrect. The sum of the digits of your guess and the hidden value are the same.
Enter your guess (must be between 10 and 99).
23
Your guess is incorrect. The sum of the digits of your guess and the hidden value are the same.
Enter your guess (must be between 10 and 99).
32
Your guess is incorrect. The sum of the digits of your guess and the hidden value are the same.
Enter your guess (must be between 10 and 99).
41
Your guess is incorrect. The sum of the digits of your guess and the hidden value are the same.
Enter your guess (must be between 10 and 99).
50
Congrats, you guessed the correct number!
Would you like to (p)lay or watch the (c)omputer play or (e)xit?
c
Enter your guess (must be between 10 and 99).
10
Your guess is incorrect. Try again.
Enter your guess (must be between 10 and 99).
11
Your guess is incorrect. Try again.
Enter your guess (must be between 10 and 99).
12
Your guess is incorrect. Try again.
Enter your guess (must be between 10 and 99).
13
Your guess is incorrect. Try again.
Enter your guess (must be between 10 and 99).
14
Your guess is incorrect. The sum of the digits of your guess and the hidden value are the same.
Enter your guess (must be between 10 and 99).
23
Your guess is incorrect. The sum of the digits of your guess and the hidden value are the same.
Enter your guess (must be between 10 and 99).
32
Congrats, you guessed the correct number!
Would you like to (p)lay or watch the (c)omputer play or (e)xit?
e
Exiting Program...

Process finished with exit code 0

*/

int DetermineSum(int number)
{
    int sum = 0;
    string numberToString;

    numberToString = to_string(number);

    for (int i = 0; i < numberToString.length(); i++)
    {
        sum += (int)numberToString[i];
    }
    return sum;
}
void PersonPlaysGame()
{
    int x;
    srand(unsigned(time(NULL)));
    x = (rand() % 90 + 10);
    int sumX = DetermineSum(x);


    int guess = -1;
    int guessSum = 0;
    bool flag = true;

    while (flag)
    {
        cout << "Enter your guess (must be between 10 and 99)." << endl;
        cin >> guess;
        guessSum = DetermineSum(guess);

        if (guess < 10 || guess > 99)
        {
            cout << "That is not a valid guess. Try again." << endl;
            continue;
        }
        else
        {
            if (guess == x)
            {
                cout << "Congrats, you guessed the correct number!" << endl;
                break;
            }
            else if (guess != x && guessSum != sumX)
            {
                cout << "Your guess is incorrect. Try again." << endl;
            }
            else if (guess != x && guessSum == sumX)
            {
                cout << "Your guess is incorrect. The sum of the digits of your guess and the hidden value are the same." << endl;
            }
            else
            {
                // Nothing
            }
        }
    }
}
void ComputerPlaysGame()
{
    int x;
    srand(unsigned(time(NULL)));
    x = (rand() % 90 + 10);
    int sumX = DetermineSum(x);

    int guess = -1;
    int guessSum = 0;

    for (int i = 10; i < 100; i++)
    {
        cout << "Enter your guess (must be between 10 and 99)." << endl;

        guess = i;
        cout << guess << endl;
        guessSum = DetermineSum(guess);

        if (guess == x)
        {
            cout << "Congrats, you guessed the correct number!" << endl;
            return;
        }
        else if (guess != x && guessSum != sumX)
        {
            cout << "Your guess is incorrect. Try again." << endl;
        }
        else if (guess != x && guessSum == sumX)
        {
            cout << "Your guess is incorrect. The sum of the digits of your guess and the hidden value are the same." << endl;
            break;
        }
        else
        {
            // Nothing
        }
    }

    for (int i = guess + 9; i < 100; i += 9)
    {

        guess = i;
        guessSum = DetermineSum(guess);
        cout << "Enter your guess (must be between 10 and 99)." << endl;
        cout << guess << endl;

        if (guess == x)
        {
            cout << "Congrats, you guessed the correct number!" << endl;
            return;
        }
        else if (guess != x && guessSum != sumX)
        {
            cout << "Your guess is incorrect. Try again." << endl;
        }
        else if (guess != x && guessSum == sumX)
        {
            cout << "Your guess is incorrect. The sum of the digits of your guess and the hidden value are the same." << endl;
        }
        else
        {
            // Nothing
        }
    }


}