#include "calculus.h"

double limit(double approaches)
{
	return approaches+0.0000001;
}

double derivative(double (*f)(double x),double x)
{
	double L = limit(0);
	return (f(x+L) - f(x)) / L;
}
