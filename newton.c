#include "newton.h"
#include "particle.h"
#include "vector.h"

#define GRAVITATIONAL_CONSTANT 1 /*TODO this isn't right*/

struct vector gravitation (struct particle a, struct particle b)
{
	struct vector F;
	F.x = GRAVITATIONAL_CONSTANT*((a.mass*b.mass)/(a.x-b.x));
	F.y = GRAVITATIONAL_CONSTANT*((a.mass*b.mass)/(a.y-b.y));
	F.z = GRAVITATIONAL_CONSTANT*((a.mass*b.mass)/(a.z-b.z));
}
