#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main()
{
	cout << "What is x in the equation x^3 + 2022x^2 = 20222022 ?" << endl;

	int x = 0;

	for (int i = 0; i < 10000; i++)
	{
		if (pow(i, 3) + 2022 * pow(i, 2) - 20222022 > 0)
		{
			x = i-1;
			break;
		}
	}

	cout << "The solution is: " << x;
}
