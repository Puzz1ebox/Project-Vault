#include <iostream>
#include <cmath>

using namespace std;

double Fee(int n)
{
    if (n == 1)
    {
        return 100;
    }
    else
    {
        return 1.5*Fee(n - 1) + 50;
    }
       
}

int main() {

    cout << Fee(1) << endl;
    cout << Fee(2) << endl;
    cout << Fee(3) << endl;
    cout << Fee(4) << endl;
    cout << Fee(5) << endl;
}