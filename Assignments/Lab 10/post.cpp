#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <list>
#include <cstring>

using namespace std;

int main()
{
    stack<string> intStack;
    bool endFlag = false;

    while (!endFlag)
    {
        string input = " ";

        cout << "Please enter the RPN expression to be evaluated:" << endl;

        while (true)
        {
            cin >> input;

            cout << "Token = ";

            if (input >= "0" && input <= "9")
            {
                cout << input;
                cout << " Push " << input << endl;
                intStack.push(input);
            }
            else if (input == "+")
            {
                cout << input;
                cout << " Pop " << intStack.top();
                int temp = stoi(intStack.top(), NULL, 0);
                intStack.pop();
                cout << " Pop " << intStack.top();
                int temp2 = stoi(intStack.top(), NULL, 0);
                intStack.pop();
                int temp3 = temp2 + temp;
                cout << " Push " << temp3 << endl;
                intStack.push(to_string(temp3));
            }
            else if (input == "-")
            {
                cout << input;
                cout << " Pop " << intStack.top();
                int temp = stoi(intStack.top(), NULL, 0);
                intStack.pop();
                cout << " Pop " << intStack.top();
                int temp2 = stoi(intStack.top(), NULL, 0);
                intStack.pop();
                int temp3 = temp2 - temp;
                cout << " Push " << temp3 << endl;
                intStack.push(to_string(temp3));
            }
            else if (input == "*")
            {
                cout << input;
                cout << " Pop " << intStack.top();
                int temp = stoi(intStack.top(), NULL, 0);
                intStack.pop();
                cout << " Pop " << intStack.top();
                int temp2 = stoi(intStack.top(), NULL, 0);
                intStack.pop();
                int temp3 = temp2 * temp;
                cout << " Push " << temp3 << endl;
                intStack.push(to_string(temp3));
            }
            else if (input == "/")
            {
                cout << input;
                cout << " Pop " << intStack.top();
                int temp = stoi(intStack.top(), NULL, 0);
                intStack.pop();
                cout << " Pop " << intStack.top();
                int temp2 = stoi(intStack.top(), NULL, 0);
                intStack.pop();
                int temp3 = temp2 / temp;
                cout << " Push " << temp3 << endl;
                intStack.push(to_string(temp3));
            }
            else if (input == ":")
            {
                cout << input;
                cout << " Pop " << intStack.top() << endl;;
                intStack.pop();
                break;
            }

           
        }

        char userInput = ' ';
        cout << endl;
        cout << "Type 'Y' or 'y' to continue or type any other letter to quit:";
        cin >> userInput;

        if (userInput != 'Y' && userInput != 'y')
        {
            break;
        }

    }
}

