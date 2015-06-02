#include <math.h>

#include "vector.h"
#include "maxwells.h"

/* F = q(E + (v X B)) */
struct vector lorentz(int q, struct vector v, struct vector E, struct vector B)
{
	struct vector F;
	F = v_add(E,v_cross(v,B));
	F = v_scalar_mul(q,F);
	return F;
}

struct vector coulombs(struct particle p1, struct particle p2)
{
	struct vector F;
	struct vector r;
	double q;
	q = p1.charge + p2.charge;
	r = v_displacement(p1.l,p2.l);
	r.x*=r.x;
	r.y*=r.y;
	r.z*=r.z;

	F.x = ke*q/r.x;
	F.y = ke*q/r.y;
	F.z = ke*q/r.z;

	return F;
}

struct vector biotsavart(struct particle p1, struct particle p2)
{
	struct vector F;
	struct vector r;
	double q;
	r = v_displacement(p1.l,p2.l);
	r.x*=r.x;
	r.y*=r.y;
	r.z*=r.z;

	q = p1.charge + p2.charge;
	q*=u0/(4*M_PI);

	F.x = q*p2.velocity.x;
	F.y = q*p2.velocity.y;
	F.z = q*p2.velocity.z;

	F = v_cross(r,F);

	return F;
}
