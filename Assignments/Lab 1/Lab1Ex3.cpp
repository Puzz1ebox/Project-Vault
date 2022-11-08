
#include <iostream>
#include <cmath>

using namespace std;

void DecomposeToTwo(int n);


int main()
{

	int numberToBeDecomposed = 0;
	bool flag = true;

	while (flag)
	{
		cout << "Enter an intiger which you want to decompose into its various factors: ";
		try
		{
			cin >> numberToBeDecomposed;
			flag = false;
		}
		catch (exception ex)
		{
			cout << "The number you entered is not an intiger, please try again!" << endl;
		}
	}

	DecomposeToTwo(numberToBeDecomposed);

	return 0;
}

void DecomposeToTwo(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			cout << n / i << "*" << i << endl;
		}
	}
}

