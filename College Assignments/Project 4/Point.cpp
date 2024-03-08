#include <iostream>
#include <cmath>
#include "Point.h"

using namespace std;
// Implement the five member functions.

Point::Point()
{
	myX = 0.0;
	myY = 0.0;
}

Point::Point(double x, double y)
{
	myX = x;
	myY = y;
}

double Point::CalculateDistanceTo(Point point2)
{
	double Distance = sqrt(pow((this->myX - point2.myX), 2) + pow((this->myY - point2.myY),2));
	return Distance;
}

Point Point::FindMiddlePointTo(Point point2)
{
	double middleX;
	double middleY;

	middleX = (this->myX + point2.myX) / 2;
	middleY = (this->myY + point2.myY) / 2;

	Point *middlePoint = new Point(middleX, middleY);

	return *middlePoint;
}

void Point::Display()
{
	cout << "(" << this->myX << ", " << this->myY << ")";
}