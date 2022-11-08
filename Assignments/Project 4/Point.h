#pragma once
#include <string>

#pragma once
class Point {
public:
	// The Point class should have 5 member functions
	// Please add declaration in the following
	// 1: The default constructor. Sets the point to (0, 0)
	// 2: An explicit value constructor, take two double values and set the 
	// Point's coordinates
		// 3: CalculateDistanceTo: take another Point as parameter, and return the 
		// distance to it
		// 4: FindMiddlePointTo: take another Point as parameter, and return the 
		// middle point between that point and itself
		// 5: Display(): Print the point coordinates to the screen.
		// Format should be "(myX, myY)".

	Point();
	Point(double x, double y);
	double CalculateDistanceTo(Point point2);
	Point FindMiddlePointTo(Point point2);
	void Display();
private:
	double myX;
	double myY;
};