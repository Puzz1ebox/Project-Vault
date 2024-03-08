#include <iostream>
#include <string>
using namespace std;

int Count1UpTo(int number);
int Count1s(int number);

int main()
{
	int number;

	cout << "Please enter a number. The program will count up to that number, then count the number of ones that occur: ";
	cin >> number;

	int totalCount = Count1UpTo(number);

	for (int i = 1; i <= number; i++)
	{
		if (i != number)
		{
			cout << i << ", ";
		}
		else
		{
			cout << i << endl;
		}
	}

	cout << "The total number of ones counted is: " << totalCount << endl;

}

int Count1s(int number)
{
	string integer = to_string(number);
	int count = 0;

	for (int i = 0; i < integer.length(); i++)
	{
		if (integer[i] == '1')
		{
			count++;
		}
	}

	return count;
}

int Count1UpTo(int number)
{
	int totalCount = 0;

	for (int i = 1; i <= number; i++)
	{
		totalCount += Count1s(i);
	}

	return totalCount;
}

