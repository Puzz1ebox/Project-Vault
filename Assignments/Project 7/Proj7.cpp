/**
*
*Assignment#7
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
https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines
*
*Student Name: Raymond A Bailey
*
*PSU user ID: XXX6548
*
*PSU email: rab6548@psu.edu
*
*CMPSC122 Fall 2022
*
*Due Time: 11:59PM, 24OCT22
*
*Time of Last Modification: 11:33AM, 24OCT22
*Description: Tests various functions concerning linked lists.
*
*/





#include <iostream>
#include <stack>

using namespace std;

/******************************************************************************
 * Node class declaration.
 * DO NOT modify.
******************************************************************************/

class Node {
public:
    int data;
    Node* next;
};

/******************************************************************************
* Functions you have to implement
******************************************************************************/

//Problem A: Remove part of a linked list.
void Remove(Node*& llist, unsigned s, unsigned t)
{
    Node* addressing;
    addressing = llist;

    for (int i = 0; i < s; i++)
    {
        if (i <= 0)
        {
            addressing = llist;
        }
        else
        {
            addressing = addressing->next;
        }
    }

    if (s != 0)
    {
        for (int i = 0; i < t - s + 1; i++)
        {
            addressing->next = addressing->next->next;
        }
    }
    else
    {
        addressing = llist;
        for (int i = 0; i < t + 1; i++)
        {
            addressing = addressing->next;
        }

        llist = addressing;
    }

}
//Problem B: Reversing a linked list.
void ReverseList(Node*& llist)
{
    Node* addressing = llist;
    int length = 0;

    while (addressing != NULL)
    {
        addressing = addressing->next;
        length++;
    }

    addressing = llist;

    int* arr = new int[length];

    for (int i = 0; i < length; i++)
    {
        arr[length - i - 1] = addressing->data;
        addressing = addressing->next;
    }

    addressing = llist;

    for (int i = 0; i < length; i++)
    {
        addressing->data = arr[i];
        addressing = addressing->next;
    }

    delete[] arr;
}

//Problem C: Perform a right shift to a Linked List.
void RightShift(Node*& llist)
{
    Node* addressing = llist;
    int length = 0;

    while (addressing != NULL)
    {
        addressing = addressing->next;
        length++;
    }

    addressing = llist;
    int* arr = new int[length];

    for (int i = 1; i < length; i++)
    {
        addressing = addressing->next;
    }

    if (length != 0)
    {
        arr[0] = addressing->data;
    }
    addressing = llist;

    for (int i = 1; i < length; i++)
    {
        arr[i] = addressing->data;
        addressing = addressing->next;
    }

    addressing = llist;

    for (int i = 0; i < length; i++)
    {
        addressing->data = arr[i];
        addressing = addressing->next;
    }

    delete[] arr;


}

//Problem D: Test if a list is a palindrome.
bool IsPalindrome(Node* llist)
{
    Node* addressing = llist;
    int length = 0;

    while (addressing != NULL)
    {
        addressing = addressing->next;
        length++;
    }

    int* arr = new int[length];
    addressing = llist;

    for (int i = 0; i < length; i++)
    {
        arr[i] = addressing->data;
        addressing = addressing->next;
    }

    addressing = llist;

    for (int i = 0; i < length; i++)
    {
        if (arr[length - i - 1] == addressing->data)
        {
            addressing = addressing->next;
            continue;
        }
        else
        {
            return false;
        }
    }

    delete[] arr;
    return true;
}


/******************************************************************************
 * Functions that used by the driver.
 * DO NOT modify these functions.
******************************************************************************/

Node* CreateList(int* arr, int len) {
    if (len <= 0 || arr == NULL) {
        return NULL;
    }
    Node* head = new Node();
    head->data = arr[len - 1];
    head->next = NULL;
    for (int i = 1; i < len; i++) {
        Node* temp = new Node();
        temp->next = head;
        temp->data = arr[len - i - 1];
        head = temp;
    }
    return head;
}

void RemoveAll(Node*& first) {
    Node* cur = first;
    while (cur != NULL) {
        Node* del = cur;
        cur = cur->next;
        delete del;
    }
    first = NULL;
}

void ShowList(Node* llist) {
    Node* cur = llist;
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

/******************************************************************************
 * Test driver main function.
 * DO NOT modify the main function.
 ******************************************************************************/

int main() {

    cout << "Problem A, test case 1, removing [2]-[4]:" << endl;
    int a[] = { 2,5,8,10,15 };
    Node* llistA = CreateList(a, 5);
    ShowList(llistA);
    cout << "Result List:" << endl;
    Remove(llistA, 2, 4);
    ShowList(llistA);

    cout << "Problem A, test case 2, removing [0]-[3]:" << endl;
    int b[] = { 1,6,8,13,15,26,30 };
    Node* llistB = CreateList(b, 7);
    ShowList(llistB);
    cout << "Result List:" << endl;
    Remove(llistB, 0, 3);
    ShowList(llistB);

    ///////////////////////////////////////////////////

    RemoveAll(llistA);
    RemoveAll(llistB);
    llistA = CreateList(a, 5);
    llistB = CreateList(b, 7);

    cout << "Problem B, test case 1, reversing list:" << endl;
    ShowList(llistA);
    cout << "Reversed List:" << endl;
    ReverseList(llistA);
    ShowList(llistA);

    cout << "Problem B, test case 2, reversing list:" << endl;
    ShowList(llistB);
    cout << "Reversed List:" << endl;
    ReverseList(llistB);
    ShowList(llistB);

    ///////////////////////////////////////////////////

    RemoveAll(llistA);
    RemoveAll(llistB);
    llistA = CreateList(a, 5);
    llistB = CreateList(b, 7);

    cout << "Problem C, test case 1, right shift:" << endl;
    ShowList(llistA);
    cout << "Resulting List:" << endl;
    RightShift(llistA);
    ShowList(llistA);

    cout << "Problem C, test case 2, right shift:" << endl;
    ShowList(llistB);
    cout << "Resulting List:" << endl;
    RightShift(llistB);
    ShowList(llistB);

    //////////////////////////////////////////////////

    cout << "Problem D, test case 1, test if palindrome:" << endl;
    int g[] = { 1,4,6,7,6,4,1 };
    Node* llistG = CreateList(g, 7);
    ShowList(llistG);
    cout << ((IsPalindrome(llistG)) ? "True" : "False") << endl;

    cout << "Problem D, test case 2, test if palindrome:" << endl;
    int h[] = { 1,4,6,7,6,4 };
    Node* llistH = CreateList(g, 6);
    ShowList(llistH);
    cout << ((IsPalindrome(llistH)) ? "True" : "False") << endl;
}

/* 

OUTPUT: NOTE TEST CASE TWO MUST BE MODIFIED FROM 2, 4 TO 0, 3 TO MEET GUIDELINES

Problem A, test case 1, removing [2]-[4]:
2 5 8 10 15
Result List:
2 5
Problem A, test case 2, removing [0]-[3]:
1 6 8 13 15 26 30
Result List:
15 26 30
Problem B, test case 1, reversing list:
2 5 8 10 15
Reversed List:
15 10 8 5 2
Problem B, test case 2, reversing list:
1 6 8 13 15 26 30
Reversed List:
30 26 15 13 8 6 1
Problem C, test case 1, right shift:
2 5 8 10 15
Resulting List:
15 2 5 8 10
Problem C, test case 2, right shift:
1 6 8 13 15 26 30
Resulting List:
30 1 6 8 13 15 26
Problem D, test case 1, test if palindrome:
1 4 6 7 6 4 1
True
Problem D, test case 2, test if palindrome:
1 4 6 7 6 4
False

C:\Users\Puzz1ebox\source\repos\Proj7\x64\Debug\Proj7.exe (process 15636) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . 


*/