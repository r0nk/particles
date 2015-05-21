#include "calculus.h"
#include <stdio.h>

double limit(double approaches)
{
	return approaches+0.000000001;
}

double derivative(double (*f)(double x),double x)
{
	double L = limit(0);
	return (f(x+L) - f(x)) / L;
}

double intergral(double a,double b,double (*f)(double x))
{
	double i,sum=0;
	double L = limit(0);
	for(i=a;i<=b;i+=L)
		sum+=f(i)*L;
	return sum;
}
