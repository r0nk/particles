#include <stdlib.h>
#include <stdio.h>

#include "newton.h"
#include "particle.h"
#include "vector.h"

const double G = 6.673E-11; /* gravitational constant */

struct vector gravitation (struct particle a, struct particle b)
{
	struct vector F = {0,0,0};
	double m = a.mass * b.mass;
	struct vector r = v_displacement(a.l,b.l);
	F.x = G*(m/r.x);
	F.y = G*(m/r.y);
	F.z = G*(m/r.z);
	return F;
}
