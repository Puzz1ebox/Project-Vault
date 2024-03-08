// CMPSC122 Lab 3 Ex 1 Skeleton Codes
#include <iostream>

using namespace std;

int* append(int* A, int lengthA, int* B, int lengthB);

int* merge(int* A, int lengthA, int* B, int lengthB);

void print(int* A, int lengthA);

int main()
{
    int a[] = { 11,33,55,77,99 };

    int b[] = { 22,44,66,88 };

    print(a, 5);

    print(b, 4);

    int* c = append(a, 5, b, 4); // c points to the appended array

    print(c, 9);

    delete c;
}

/* Output 
{ 11,33,55,77,99 }
{ 22,44,66,88 }
{ 11,33,55,77,99,22,44,66,88 }

\\udrive.ad.psu.edu\users\r\a\rab6548\Desktop\Temporary Lab Workspace\Lab 3\Lab3Ex1\x64\Debug\Lab3Ex1.exe (process 3104) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/

void print(int* a, int n)
{
    cout << "{ ";

    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            cout << a[i] << ",";
        }
        else
        {
            cout << a[i] << " }" << endl;
        }
        
    }
}
int* append(int* a, int m, int* b, int n)
{
    int* result = new int[m + n];
   
    for (int i = 0; i < m; i++)
    {
        result[i] = a[i];
    }

    for (int i = 0; i < n; i++)
    {
        result[i + m] = b[i];
    }

    return result;
}