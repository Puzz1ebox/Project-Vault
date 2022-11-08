/**
*
*Assignment#
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
*Due Time: 11:59PM, 31AUG22
*
*Time of Last Modification: 10:13AM, 30AUG22
*Description: Find's the maximum profit attainable for any given 10 day line-up of stock prices
*
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// functions
void buy(int& funds, int price, int& shares);
void sell(int& shares, int price, int& funds);

int main() {

    int funds = 100;
    int shares = 0;

    vector<int> lineup(10, 0);

    cout << "Enter the 10 day stock price: ";

    for (int i = 0; i < 10; i++)
    {
        cin >> lineup[i];
    }


    for (int i = 0; i < lineup.size(); i++)
    {
        // Logic for what to do when in the middle of the vector

        if (i != 0 && i != 9) {
            if (lineup[i - 1] > lineup[i] && lineup[i] < lineup[i + 1]) 
            {
                buy(funds, lineup[i], shares);
                cout << "Buy " << shares << " shares on day " << i << " using $" << shares * lineup[i] << " (Remaining fund: $" << funds << ". Shares held: " << shares << ")" << endl;
            }
            else if (lineup[i - 1] < lineup[i] && lineup[i] > lineup[i + 1])
            {
                cout << "Sell " << shares << " shares on day " << i << " for $" << shares * lineup[i] << " (Remaining fund: $" << funds+(shares*lineup[i]) << ". Shares held: " << shares << ")" << endl;
                sell(shares, lineup[i], funds);
            }
            else 
            {
                continue;
            }
        }

        // Prevents vector going over maximum index

        else if (i == 9)
        {
            if (lineup[i] > lineup[i - 1])
            {
                cout << "Sell " << shares << " shares on day " << i << " for $" << shares * lineup[i] << " (Remaining fund: $" << funds+(shares * lineup[i]) << ". Shares held: " << shares << ")" << endl;
                sell(shares, lineup[i], funds);
            }
            else
            {
                // do nothing
            }
        }

        // Prevents vector going under minimum index

        else
        {
            if (lineup[i] < lineup[i + 1])
            {
                buy(funds, lineup[i], shares);
                cout << "Buy " << shares << " shares on day " << i << " using $" << shares * lineup[i] << " (Remaining fund: $" << funds << ". Shares held: " << shares << ")" << endl;
            }
            else
            {
                // do nothing
            }
        }
    }

    cout << "The maximum amount of profit you can obtain is: $" << funds - 100;

    return 0;
}

// Program Output
/*
Enter the 10 day stock price: 50 55 100 30 20 25 40 12 30 27
Buy 2 shares on day 0 using $100 (Remaining fund: $0. Shares held: 2)
Sell 2 shares on day 2 for $200 (Remaining fund: $200. Shares held: 2)
Buy 10 shares on day 4 using $200 (Remaining fund: $0. Shares held: 10)
Sell 10 shares on day 6 for $400 (Remaining fund: $400. Shares held: 10)
Buy 33 shares on day 7 using $396 (Remaining fund: $4. Shares held: 33)
Sell 33 shares on day 8 for $990 (Remaining fund: $994. Shares held: 33)
The maximum amount of profit you can obtain is: $894
C:\Users\TSE\Desktop\Programs\Applications\Proj1\x64\Debug\Proj1.exe (process 11776) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/

// TSE is a corperation where I work. Please do not be alarmed.

void buy(int& funds, int price, int& shares)
{
    shares = funds / price;
    funds = funds - price * shares;
}

void sell(int& shares, int price, int& funds)
{
    funds = funds + price * shares;
    shares = 0;
}