#include <stdlib.h>
#include <stdio.h>

#include "newton.h"
#include "particle.h"
#include "vector.h"

const double G = 6.673E-11; /* gravitational constant */

inline double r(double a, double b)
{
	return (a-b)*abs(a-b);
}

struct vector gravitation (struct particle a, struct particle b)
{
	struct vector F = {0,0,0};
	double m = a.mass * b.mass;
	if(a.l.x-b.l.x)
		F.x = G*(m/r(a.l.x,b.l.x));
	if(a.l.y-b.l.y)
		F.y = G*(m/r(a.l.y,b.l.y));
	if(a.l.z-b.l.z)
		F.z = G*(m/r(a.l.z,b.l.z));
	return F;
}
