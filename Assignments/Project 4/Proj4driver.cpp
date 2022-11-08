/**
*
*Assignment #4
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
*Student Name: Raymond A. Bailey
*
*PSU user ID: XXX6548
*
*PSU email: rab6548@psu.edu
*
*CMPSC122 Fall 2022
*
*Due Time: 11:59PM, Friday, 23SEP22
*
*Time of Last Modification: 9:45AM, Wednesday, 21SEP22
*Description: Makes instances of points then does point math.
*
*/

#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;
// main() function which tests the Point class. DO NOT TOUCH
int main() {
	cout << "Creating point A using the default constuctor." << endl;
	Point pointA;
	cout << "Displaying the coordinates of point A: ";
	pointA.Display();
	cout << endl;
	cout << "Please enter x and y coordinates for point B, seperated by blank space: ";
		double xb, yb;
	cin >> xb >> yb;
	cout << "Creating point B using the explicit value constuctor and the input x, y coordinates." << endl;
		Point pointB(xb, yb);
	cout << "Displaying the coordinates of point B: ";
	pointB.Display();
	cout << endl;
	cout << "Please enter x and y coordinates for point C, seperated by blank space: ";
		double xc, yc;
	cin >> xc >> yc;
	cout << "Creating point C using the explicit value constuctor and the input x, y coordinates." << endl;
		Point pointC(xc, yc);
	cout << "Displaying the coordinates of point C: ";
	pointC.Display();
	cout << endl;
	cout << "Distance between point B and C is: " <<
		pointB.CalculateDistanceTo(pointC) << endl;
	cout << "The middle point between point B and C is: ";
	Point pointMid = pointB.FindMiddlePointTo(pointC);
	pointMid.Display();
	cout << endl;
}
// Important: Please add an output sample of the program in the following.

/* Output

Creating point A using the default constuctor.
Displaying the coordinates of point A: (0, 0)
Please enter x and y coordinates for point B, seperated by blank space: 4 4
Creating point B using the explicit value constuctor and the input x, y coordinates.
Displaying the coordinates of point B: (4, 4)
Please enter x and y coordinates for point C, seperated by blank space: 7 7
Creating point C using the explicit value constuctor and the input x, y coordinates.
Displaying the coordinates of point C: (7, 7)
Distance between point B and C is: 4.24264
The middle point between point B and C is: (5.5, 5.5)

C:\Users\rab6548\source\repos\Proj4\x64\Debug\Proj4.exe (process 14608) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/