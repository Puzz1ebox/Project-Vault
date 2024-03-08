#include "LinearFunction.h"
void LinearFunction::Set(double a, double b)
{
	this->a = a;
	this->b = b;
}

LinearFunction::LinearFunction()
{
	this->a = 1;
	this->b = 0;
}

LinearFunction::LinearFunction(double a, double b)
{
	this->a = a;
	this->b = b;
}

double LinearFunction::Evaluate(double x)
{
	double returnValue;

	returnValue = this->a * x + this->b;

	return returnValue;
}