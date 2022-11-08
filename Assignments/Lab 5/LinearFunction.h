#pragma once
class LinearFunction
{
private:
	double a;
	double b;

public:
	void Set(double a, double b);
	LinearFunction();
	LinearFunction(double a, double b);
	double Evaluate(double x);
};

