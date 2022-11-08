#include <iostream>
#include <cmath>

using namespace std;
int CalculateCost(int n);

int CalculateCost(int n) {

	int cost = ceil((double)n / 3.0) * 4;

	return cost;
}
int main() {
	cout << "Enter the number of balls you need: " << endl;
	int n;
	cin >> n;
	if (n < 0) {
		cout << "Invalid number of balls." << endl;
		return 1;
	}
	cout << "The total cost for " << n << " balls is $" << CalculateCost(n) <<
		"." << endl;
}
