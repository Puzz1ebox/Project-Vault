
#include <iostream>
#include <array>
#include <iterator>

using namespace std;

int* append(int* A, int lengthA, int* B, int lengthB);

int* merge(int* A, int lengthA, int* B, int lengthB);

void print(int* A, int lengthA);

void sortIntArray(int* paramArray, int size);

int main()
{
    int a[] = { 1,21,3,7,4 };

    int b[] = { 8,19,11,2 };

    sortIntArray(a, 5);
    sortIntArray(b, 4);

    print(a, 5);

    print(b, 4);

    int* c = merge(a, 5, b, 4);

    print(c, 9);

    delete c;
}

/* Output

{ 1,3,4,7,21 }
{ 2,8,11,19 }
{ 1,2,3,4,7,8,11,19,21 }

\\udrive.ad.psu.edu\users\r\a\rab6548\Desktop\Temporary Lab Workspace\Lab 3\Lab3Ex1\x64\Debug\Lab3Ex1.exe (process 10364) exited with code 0.
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

int* merge(int* a, int m, int* b, int n)
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

    sortIntArray(result, m+n);

    return result;
}

void sortIntArray(int* paramArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        int temp;

        for (int j = 0; j < size; j++)
        {
            if (paramArray[i] < paramArray[j])
            {
                temp = paramArray[i];
                paramArray[i] = paramArray[j];
                paramArray[j] = temp;  
            }
            
        } 
    }
}