// ********************************************************************
// !!!!!
// Please attach output sample to the end of this file.
// !!!!!
//
#include <iostream>
#include "List.h"
using namespace std;
void InitList(List& l, ElementType* arr, int size) {
	for (int i = 0; i < size; i++) {
		l.insert(arr[i], i);
	}
}
/**
*
*Assignment #5
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
*PSU email: Rab6548@psu.edu
*
*CMPSC122 Fall 2022
*
*Due Time: 11:59PM, Monday, Oct 10th, 2022
*
*Time of Last Modification: 9:45AM, Monday, Oct 10th, 2022
*Description: Modifies the contents of lists via operator overloading
*
*/
int main() {
	int arr1A[] = { 1,3,5,7,9 };
	int arr1B[] = { 2,4,6,8 };
	List list1A, list1B;
	InitList(list1A, arr1A, 5);
	InitList(list1B, arr1B, 4);
	cout << "Test case 1. The two list: " << endl;
	cout << "list1A: ";
	list1A.display(cout);
	cout << endl;
	cout << "list1B: ";
	list1B.display(cout);
	cout << endl;
	cout << "After \"list1A += list1B\", list1A becomes: " << endl;
	list1A += list1B;
	list1A.display(cout);
	cout << endl;
	cout << "*************************************************************" <<
		endl;
	int arr2A[] = { 1,2 };
	int arr2B[] = { 2,4,6,8,1,3,5 };
	List list2A, list2B;
	InitList(list2A, arr2A, 2);
	InitList(list2B, arr2B, 7);
	cout << "Test case 2. The two list: " << endl;
	cout << "list2A: ";
	list2A.display(cout);
	cout << endl;
	cout << "list2B: ";
	list2B.display(cout);
	cout << endl;
	cout << "After \"list2A += list2B\", list2A becomes: " << endl;
	list2A += list2B;
	list2A.display(cout);
	cout << endl;
	cout << "*************************************************************" <<
		endl;
	int arr3B[] = { 3,1,2,4,8,5,3 };
	List list3A, list3B;
	InitList(list3B, arr3B, 7);
	cout << "Test case 3. The two list: " << endl;
	cout << "list3A: ";
	list3A.display(cout);
	cout << endl;
	cout << "list3B: ";
	list3B.display(cout);
	cout << endl;
	cout << "After \"list3A += list3B\", list3A becomes: " << endl;
	list3A += list3B;
	list3A.display(cout);
	cout << endl;
	cout << "*************************************************************" <<
		endl;
	int arr4A[] = { 1,2,2,4,5,6,7 };
	int arr4B[] = { 2,5,8 };
	List list4A, list4B;
	InitList(list4A, arr4A, 7);
	InitList(list4B, arr4B, 3);
	cout << "Test case 4. The two list: " << endl;
	cout << "list4A: ";
	list4A.display(cout);
	cout << endl;
	cout << "list4B: ";
	list4B.display(cout);
	cout << endl;
	cout << "After \"list4A -= list4B\", list4A becomes: " << endl;
	list4A -= list4B;
	list4A.display(cout);
	cout << endl;
	cout << "*************************************************************" <<
		endl;
	int arr5A[] = { 1,2,2,4,3,3,2 };
	int arr5B[] = { 1,2,3 };
	List list5A, list5B;
	InitList(list5A, arr5A, 7);
	InitList(list5B, arr5B, 3);
	cout << "Test case 5. The two list: " << endl;
	cout << "list5A: ";
	list5A.display(cout);
	cout << endl;
	cout << "list5B: ";
	list5B.display(cout);
	cout << endl;
	cout << "After \"list5A -= list5B\", list5A becomes: " << endl;
	list5A -= list5B;
	list5A.display(cout);
	cout << endl;
}
/*

Test case 1. The two list:
list1A: 1 3 5 7 9
list1B: 2 4 6 8
After "list1A += list1B", list1A becomes:
1 3 5 7 9 2 4 6 8
*************************************************************
Test case 2. The two list:
list2A: 1 2
list2B: 2 4 6 8 1 3 5
After "list2A += list2B", list2A becomes:
1 2 2 4 6 8 1 3 5
*************************************************************
Test case 3. The two list:
list3A:
list3B: 3 1 2 4 8 5 3
After "list3A += list3B", list3A becomes:
3 1 2 4 8 5 3
*************************************************************
Test case 4. The two list:
list4A: 1 2 2 4 5 6 7
list4B: 2 5 8
After "list4A -= list4B", list4A becomes:
1 4 6 7
*************************************************************
Test case 5. The two list:
list5A: 1 2 2 4 3 3 2
list5B: 1 2 3
After "list5A -= list5B", list5A becomes:
4

C:\Users\rab6548\source\repos\Proj5main\x64\Debug\Proj5main.exe (process 11996) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/